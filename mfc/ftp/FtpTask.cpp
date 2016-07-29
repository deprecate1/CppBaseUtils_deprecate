#include "StdAfx.h"
#include "FtpTask.h"
#include "WorkSpace.h"
#include "Utility.h"

FtpTask::FtpTask(void):pConnect(NULL)
{
	Connect2Ftp();
}

FtpTask::~FtpTask(void)
{
	CloseConnection();
}

//////////////////////////////////////////////////////////////////////////
//测试FTP联接
bool FtpTask::TestFtpConnection(CString server,CString user,CString pwd,INTERNET_PORT port,CString& exceptionInfo)
{
	try
	{
		CFtpConnection* pConnect = NULL;
		CInternetSession sess;			
		pConnect = sess.GetFtpConnection(server,user,pwd,port);	
		bool ok =  pConnect != NULL;
		if(pConnect != NULL)
			delete pConnect;
		return ok;
	}
	catch (CException* e)
	{
		exceptionInfo = Utility::GetErrorInfoFromException(e);
		return false;
	}	
}

bool FtpTask::Connect2Ftp()
{
	try
	{		
		WorkSpace* ws = WorkSpace::GetCurWorkspace();
		if(ws != NULL)
		{
			CString server= ws->GetFTPServer().c_str();
			CString user=ws->GetFTPLogName().c_str();
			CString pwd=ws->GetFTPPassword().c_str();
			INTERNET_PORT port = ws->GetFTPPort();
			pConnect = sess.GetFtpConnection(server,user,pwd,port);	
			//设置当前目录为根目录
			pConnect->SetCurrentDirectory(_T("/"));
		}
		return pConnect != NULL;
	}
	catch (CException* e)
	{
		//抛出异常
		throw CString(_T("联接FTP失败！"));
	}	
}

CString FtpTask::FindFile(CString name)
{
	if(pConnect == NULL)
		return _T("");
	CFtpFileFind finder(pConnect);
	if(finder.FindFile(name) == TRUE)
		return finder.GetFileURL();
	return _T("");
}

void FtpTask::CloseConnection()
{
	if(pConnect != NULL)
	{
		pConnect->Close();
		delete pConnect;
		pConnect = NULL;
	}
}

//////////////////////////////////////////////////////////////////////////
//上传文件到服务器
bool FtpTask::UploadFile(CString strLocalFile ,CString strRemoteDirectory)
{
	if(pConnect != NULL)
	{
		pConnect->SetCurrentDirectory(_T("/"));
		CString fn = Utility::GetFileNameFromFullPath(strLocalFile);
		CString ftppath;
		ftppath.Format(_T("%s/%s"),strRemoteDirectory,fn);
		BOOL bworking = pConnect->PutFile(strLocalFile,ftppath);
		return bworking;
	}
	return false;
}

//上传文件
bool FtpTask::UploadFile(CString strLocalFile ,CString strRemoteDirectory,CString fileName)
{
	if(pConnect != NULL)
	{
		pConnect->SetCurrentDirectory(_T("/"));		
		CString ftppath;
		ftppath.Format(_T("%s/%s"),strRemoteDirectory,fileName);
		BOOL bworking = pConnect->PutFile(strLocalFile,ftppath);
		return bworking;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
//下载服务器上的文件到本地
//strRemoteFile:服务器文件完整路径，strLocalDirectory：本地文件完整路径，boverwrite：是否覆盖本地文件
bool FtpTask::DownloadFile(CString strRemoteFile,CString strLocalFile,bool boverwrite)
{
	if(pConnect != NULL)
	{	
		BOOL bWorking = pConnect->SetCurrentDirectory(_T("/"));
		//GetFile的文件参数为当前目录下的相对路径
		BOOL bfail = !boverwrite;
		bWorking = pConnect->GetFile(strRemoteFile,strLocalFile,bfail);
		return bWorking;
	}	
	return false;
}


//////////////////////////////////////////////////////////////////////////
//是否为目录
bool FtpTask::IsDirectory(CString name)
{
	if(pConnect != NULL)
	{
		BOOL bWorking = pConnect->SetCurrentDirectory(name);
		return bWorking;
	}
	return NULL;	 
}


//////////////////////////////////////////////////////////////////////////
//文件或目录是否存在
bool FtpTask::IsExist(CString name)
{
	if(pConnect != NULL)
	{
		CFtpFileFind finder(pConnect);
		BOOL bWorking = finder.FindFile(name);
		return bWorking;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
//获取指定目录下所有子目录
void FtpTask::GetAllSubDirectories(CString directoryName,CStringArray& directories)
{
	if(pConnect == NULL)
		return ;
	BOOL bWorking  = pConnect->SetCurrentDirectory(directoryName);
	if(bWorking)
	{
		CFtpFileFind finder(pConnect);
		bWorking = finder.FindFile(_T("*"));
		while (bWorking)
		{
			bWorking = finder.FindNextFile();
			if (finder.IsDirectory())
			{
				CString str = finder.GetFilePath();
				CString dd = finder.GetFileName();
				CString name;
				name.Format(_T("%s/%s"),str,dd);
				directories.Add(name);
			}
		}
	}	
}

//////////////////////////////////////////////////////////////////////////
//获取目录下所有dwg文件
void FtpTask::GetAlldwgFilesAtDirectory(CString directory,CStringArray& files)
{
	if(pConnect == NULL)
		return;
	CFtpFileFind finder(pConnect);
	BOOL bWorking  = pConnect->SetCurrentDirectory(directory);
	bWorking = finder.FindFile(_T("*"));
	
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if (!finder.IsDirectory() && !finder.IsDots())
		{
			CString str = finder.GetFilePath();
			CString name = finder.GetFileName();			
			if (name.Right(4).CompareNoCase(CString(_T(".DWG"))) ==0 )
			{				
				files.Add(name);
			}				
		}		
	}
}

//////////////////////////////////////////////////////////////////////////
//删除FTP下的文件
bool FtpTask::DeleteFile(CString strRemoteFile)
{
	if(pConnect != NULL)
	{
		BOOL bWorking = pConnect->SetCurrentDirectory(_T("/"));
		if(bWorking)
			bWorking = pConnect->Remove(strRemoteFile);
		return bWorking;
	}
	return false;
}
