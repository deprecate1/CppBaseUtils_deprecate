#pragma once
#include <afxinet.h>

//建立FTP连接，实现文件上传下载功能
class FtpTask
{
public:
	FtpTask(void);
public:
	~FtpTask(void);

private:
	//连接到Ftp
	bool Connect2Ftp();	
	//关闭连接
	void CloseConnection();
	//返回指定文件的服务器路径
	CString FindFile(CString name);

public:
	//上传文件
	bool UploadFile(CString strLocalFile ,CString strRemoteDirectory);
	bool UploadFile(CString strLocalFile ,CString strRemoteDirectory,CString fileName);
	//下载文件
	bool DownloadFile(CString strRemoteFile,CString strLocalFile,bool boverwrite);	

	//是否目录
	bool IsDirectory(CString name);
	//文件或目录是否存在
	bool IsExist(CString name);	
	//获取指定目录下所有子目录
	void GetAllSubDirectories(CString directoryName,CStringArray& directories);
	//获取指定目录下所有dwg文件
	void GetAlldwgFilesAtDirectory(CString directory,CStringArray& files);	
	//删除指定文件
	bool DeleteFile(CString strRemoteFile);

public:
	//测试FTP连接
	static bool TestFtpConnection(CString server,CString user,CString pwd,INTERNET_PORT port,CString& exceptionInfo);

private:
	CInternetSession sess;
	CFtpConnection* pConnect;
};
