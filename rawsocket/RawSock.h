#ifndef RAW_SOCK_H
#define RAW_SOCK_H

#include <cstring>
#include <cmath>
#include <conio.h>
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

// ===============================================================
//Mac头部，总长度14字节
typedef struct _eth_hdr
{
	unsigned char dstmac[6]; //目标mac地址
	unsigned char srcmac[6]; //源mac地址
	unsigned short eth_type; //以太网类型
}eth_hdr;

//IP头部，总长度20字节
typedef struct _ip_hdr
{
	unsigned char version;   //版本
	unsigned char tos;       //服务类型
	unsigned short tot_len;  //总长度
	unsigned short id;       //标志
	unsigned short frag_off; //分片偏移
	unsigned char ttl;       //生存时间
	unsigned char protocol;  //协议
	unsigned short chk_sum;  //检验和
	struct in_addr srcaddr;  //源IP地址
	struct in_addr dstaddr;  //目的IP地址
}ip_hdr;

//TCP头部，总长度20字节
typedef struct _tcp_hdr
{
	unsigned short src_port;    //源端口号
	unsigned short dst_port;    //目的端口号
	unsigned int seq_no;        //序列号
	unsigned int ack_no;        //确认号
#if 1
	unsigned char reserved_1:4; //保留6位中的4位首部长度
	unsigned char thl:4;        //tcp头部长度
	unsigned char flag:6;       //6位标志
	unsigned char reseverd_2:2; //保留6位中的2位
#else
	unsigned char thl:4;        //tcp头部长度
	unsigned char reserved_1:4; //保留6位中的4位首部长度
	unsigned char reseverd_2:2; //保留6位中的2位
	unsigned char flag:6;       //6位标志 
#endif
	unsigned short wnd_size;    //16位窗口大小
	unsigned short chk_sum;     //16位TCP检验和
	unsigned short urgt_p;      //16为紧急指针
}tcp_hdr;

//UDP头部，总长度8字节
typedef struct _udp_hdr
{
	unsigned short src_port; //远端口号
	unsigned short dst_port; //目的端口号
	unsigned short uhl;      //udp头部长度
	unsigned short chk_sum;  //16位udp检验和
}udp_hdr;

//ICMP头部，总长度4字节
typedef struct _icmp_hdr
{
	unsigned char icmp_type;   //类型
	unsigned char code;        //代码
	unsigned short chk_sum;    //16位检验和
}icmp_hdr; 

// ===============================================================
#define PROT_ICMP		1		// Internet Control Message                 [RFC792] 
#define PROT_TCP		6		// Transmission Control                     [RFC793]
#define PROT_UDP		17		// User Datagram                            [RFC768][JBP]

// ===============================================================
#define MAX_PACKET_SIZE		0x40000
#define MAX_ADAPTER_NUMBER	128

// ===============================================================

#define SIO_RCVALL    (IOC_IN|IOC_VENDOR|1)
class CMainFrame;

class CRawSocket
{
public:
	static int EnumAdapters();
	static void DebugAdapters();
	static TCHAR adapter_ip[MAX_ADAPTER_NUMBER][32];
	static TCHAR *adapter_des[MAX_ADAPTER_NUMBER];
	static int adapter_number;

public:
	CRawSocket(int adapter_id, CMainFrame *pMainFrame)
	{
		m_adapter_id = adapter_id;
		m_mainframe = pMainFrame;
		m_enabled = FALSE;

		ZeroMemory(buffer, MAX_PACKET_SIZE);
		s = INVALID_SOCKET;
		flag = 0;
		Init();
	};
	~CRawSocket()
	{
		::closesocket(s);
		s = INVALID_SOCKET;
	};
	void Start(void);
	void Stop(void);
	void* GetSniffData(int *len);

public:
	int			m_adapter_id;
	CMainFrame		*m_mainframe;
	BOOL			m_enabled;

private:
	int Init(void);

	SOCKET			s;
	SOCKADDR_IN		sa;
	int			flag;
	BYTE			buffer[MAX_PACKET_SIZE];
};
#endif
