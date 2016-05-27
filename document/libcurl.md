下载
===
官方网站https://curl.haxx.se/download.html找到:

https://curl.haxx.se/download/curl-7.49.0.zip


编译
===
程序拷贝到d:\sdk，这个和属性表有关，建议第三方库都统一放这里

打开curl-7.49.0\projects\Windows\VC14\curl-all.sln编译两个项目"DLL Release/Win32"和"DLL Debug/Win32"

得到libcurl.dll和libcurld.dll，拷贝到D:\sdk\bin并添加这个路径到path



属性表
===
参考props\libcrul.props


例子
===

	#include "curl/curl.h"
	void CMFCApplication1Dlg::OnBnClickedButton1()
	{
		// TODO: 在此添加控件通知处理程序代码	curl_global_init(CURL_GLOBAL_ALL);
		CURL* curl = curl_easy_init();
		if (NULL == curl)
		{
			MessageBox(L"curl_easy_init() return error", L"error", MB_ICONINFORMATION);
		}
	}
