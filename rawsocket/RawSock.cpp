#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "RawSock.h"
#include "PcapRW.h"
#include <IPHlpApi.h>
#include <IPIfCons.h>
#include <WS2tcpip.h>
#include <tchar.h>
#include "../../include/xtrace/xtrace.h"

using namespace std;

#define ULONG_BYTE4(u)		((u & 0xFF000000) >> 24)
#define ULONG_BYTE3(u)		((u & 0xFF0000) >> 16)
#define ULONG_BYTE2(u)		((u & 0xFF00) >> 8)
#define ULONG_BYTE1(u)		(u & 0xFF)

#define BYTE_L(u)		(u & 0xF)
#define BYTE_H(u)		(u >> 4)

int CRawSocket::adapter_number = -1;
TCHAR CRawSocket::adapter_ip[MAX_ADAPTER_NUMBER][32] = {0 };
TCHAR *CRawSocket::adapter_des[MAX_ADAPTER_NUMBER] = {0 };

int CRawSocket::EnumAdapters()
{
	if(adapter_number > 0)
		return 0;

	if(adapter_number == 0)
		return -1;

	WSADATA	WSAData;
	if(0 != ::WSAStartup(MAKEWORD(2, 2), &WSAData)) {
		MessageBox (NULL, L"ERROR", L"WSAStartup() failed.", MB_OK);
		return -2;
	}

	IP_ADAPTER_INFO *pAdapterInfo = NULL;
	IP_ADAPTER_INFO  *pAdapter = NULL;
	DWORD dwRetVal = 0;
	pAdapterInfo = (IP_ADAPTER_INFO *) malloc( sizeof(IP_ADAPTER_INFO) );
	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);

	if (GetAdaptersInfo( pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		free(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO *) malloc (ulOutBufLen);
		if (pAdapterInfo == NULL)
		{
			printf("Error allocating memory needed to call GetAdaptersinfo.\n");
			return -3;
		}
	}

	if ((dwRetVal = GetAdaptersInfo( pAdapterInfo, &ulOutBufLen)) != NO_ERROR)
	{
		printf("GetAdaptersInfo failed with error: %d\n", dwRetVal);
		if (pAdapterInfo)
			free(pAdapterInfo);
		return -4;
	}

	pAdapter = pAdapterInfo;
	adapter_number = 0;
	while (NULL != pAdapter && adapter_number < MAX_ADAPTER_NUMBER)
	{
		wcscpy(adapter_ip[adapter_number], A2W(pAdapter->IpAddressList.IpAddress.String));
		adapter_des[adapter_number] = (TCHAR *)malloc(1024 * 2);
		wcscpy(adapter_des[adapter_number], A2W(pAdapter->Description));

		pAdapter = pAdapter->Next;
		adapter_number++;
	}

	if (pAdapterInfo)
		free(pAdapterInfo);

	return 0;
}

void CRawSocket::DebugAdapters()
{
#if 0
	XTRACE(RGB(0, 0, 0), _T("adapter_number: %d\n"), adapter_number);
	int i;
	for (i = 0; i < adapter_number; i++) {
		XTRACE(RGB(0, 0, 0), _T("name: %s, descriptor: %s\n"), adapter_ip[i], adapter_des[i]);
	}
#endif
}

int CRawSocket::Init(void)
{
	s = ::socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	if (INVALID_SOCKET == (int)s) {
		MessageBox(NULL, L"ERROR", L"socket() failed.", MB_OK);
		return -2;
	}

	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr(W2A(CRawSocket::adapter_ip[m_adapter_id]));
	if (-1 == ::bind(s, (SOCKADDR *)&sa, sizeof(SOCKADDR))) {
		MessageBox(NULL, L"ERROR", L"bind() failed.", MB_OK);
		return -2;
	}

	return 0;
}

void CRawSocket::Start(void)
{
	m_enabled = TRUE;

	u_long flag = 1;
	::ioctlsocket(s, SIO_RCVALL, (u_long*)&flag);
}
void CRawSocket::Stop(void)
{
	m_enabled = FALSE;

	u_long flag = 0;
	::ioctlsocket(s, SIO_RCVALL, (u_long*)&flag);
}

// the f**k new windows limit of raw socket, we build pseudo eth head
#define PCAP_HEAD_SIZE		16		// pcap文件格式中每帧的头
#define IPV4_ETH_HEAD_SIZE	14		// mac头14字节
void* CRawSocket::GetSniffData(int *len)
{
	if(NULL == len)
		return NULL;

	int count = ::recv(s, (char*)buffer + PCAP_HEAD_SIZE + IPV4_ETH_HEAD_SIZE, MAX_PACKET_SIZE - PCAP_HEAD_SIZE - IPV4_ETH_HEAD_SIZE, 0);
	if (count <= 0) {
		return NULL;
	} else {
		*len = count + PCAP_HEAD_SIZE + IPV4_ETH_HEAD_SIZE;
		buffer[PCAP_HEAD_SIZE + 0] = 0x00;
		buffer[PCAP_HEAD_SIZE + 1] = 0x00;
		buffer[PCAP_HEAD_SIZE + 2] = 0x00;
		buffer[PCAP_HEAD_SIZE + 3] = 0x00;
		buffer[PCAP_HEAD_SIZE + 4] = 0x00;
		buffer[PCAP_HEAD_SIZE + 5] = 0x00;
		buffer[PCAP_HEAD_SIZE + 6] = 0x00;
		buffer[PCAP_HEAD_SIZE + 7] = 0x00;
		buffer[PCAP_HEAD_SIZE + 8] = 0x00;
		buffer[PCAP_HEAD_SIZE + 9] = 0x00;
		buffer[PCAP_HEAD_SIZE + 10] = 0x00;
		buffer[PCAP_HEAD_SIZE + 11] = 0x00;
		buffer[PCAP_HEAD_SIZE + 12] = 0x08;
		buffer[PCAP_HEAD_SIZE + 13] = 0x00;

		pcaprec_hdr *pcaprec = (pcaprec_hdr *)buffer;
		SYSTEMTIME wtm;
		::GetLocalTime(&wtm);

		time_t clock;
		struct tm tm;
		tm.tm_year = wtm.wYear - 1900;
		tm.tm_mon = wtm.wMonth - 1;
		tm.tm_mday = wtm.wDay;
		tm.tm_hour = wtm.wHour;
		tm.tm_min = wtm.wMinute;
		tm.tm_sec = wtm.wSecond;
		tm.tm_isdst = -1;
		clock = mktime(&tm);

		// 数据链表
		pcaprec->orig_len = count + IPV4_ETH_HEAD_SIZE;
		pcaprec->incl_len = count + IPV4_ETH_HEAD_SIZE;
		pcaprec->ts_sec = (unsigned int)clock;
		pcaprec->ts_usec = wtm.wMilliseconds * 1000;

		return (void *)buffer;
	}
}
