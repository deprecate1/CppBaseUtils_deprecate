#include "stdafx.h"
#include "stdio.h"
#include <vector>
#include <iostream>
#include <string>
#include <curl/curl.h>

#include "CLibcurlWrap.h"

class CLibcurlWrap2
{
public:
	CLibcurlWrap2() {}
	~CLibcurlWrap2() {}

private:
	IN TCHAR	*m_urlpath;
	void		*m_buffer;
	int		*m_len;

public:
	bool GetUrlContent(IN TCHAR *urlpath, OUT void *buffer, OUT int *len)
	{
		USES_CONVERSION;
		if (NULL == urlpath || NULL == buffer || NULL == len)
			return false;

		m_urlpath	= urlpath;
		m_buffer	= buffer;
		m_len		= len;

		CURLcode res;
		curl_global_init(CURL_GLOBAL_ALL);
		CURL* curl = curl_easy_init();
		if (NULL == curl)
		{
			return CURLE_FAILED_INIT;
		}

		curl_easy_setopt(curl, CURLOPT_URL, W2A(m_urlpath));
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, __OnWriteData);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

		curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		if (CURLE_OK == res) {
			return true;
		}
		return false;
	}

private:
	static size_t __OnWriteData(void* buffer, size_t size, size_t nmemb, void* lpVoid)
	{
		CLibcurlWrap2 *obj = (CLibcurlWrap2*)lpVoid;
		return obj->OnWriteData(buffer, size, nmemb);
	}

	size_t OnWriteData(void* buffer, size_t size, size_t nmemb)
	{
		*m_len = size * nmemb;
		memcpy(m_buffer, buffer, *m_len);
		return *m_len;
	}
};

// =============================================
// 代理模式
// =============================================
CLibcurlWrap::CLibcurlWrap()
{
	m_obj = new CLibcurlWrap2();
}

CLibcurlWrap::~CLibcurlWrap()
{
	delete((CLibcurlWrap2 *)m_obj);
}

bool CLibcurlWrap::GetUrlContent(IN TCHAR *urlpath, OUT void *buffer, OUT int *len)
{
	return ((CLibcurlWrap2 *)m_obj)->GetUrlContent(urlpath, buffer, len);
}
