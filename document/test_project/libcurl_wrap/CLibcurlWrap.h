#ifndef __LIBCURL_WRAP_026535657_H_
#define __LIBCURL_WRAP_026535657_H_

#define IN	const
#define OUT

class CLibcurlWrap
{
public:
	CLibcurlWrap();
	~CLibcurlWrap();

public:
	bool GetUrlContent(IN TCHAR *urlpath, OUT void *buffer, OUT int *len);

private:
	void	*m_obj;
};

#endif
