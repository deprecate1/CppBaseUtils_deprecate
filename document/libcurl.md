https://curl.haxx.se/download.html，
下载curl-7.48.0.tar.bz2


打开curl-7.48.0\projects\Windows\VC14\curl-all.sln编译win32 static lib得到libcurl.lib

新的visual studio工程设置：预定义宏CURL_STATICLIB，库libcurl.lib;ws2_32.lib;wldap32.lib
