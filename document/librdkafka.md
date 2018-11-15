1.参考文章：librdkafka-0.11.6\README.win32

2.注意：openssl下载github上的版本：OpenSSL_1_1_1
编译方法见openssl

3.用vs2013打开工程，打开librdkafka的设置，选项改为All Configurations, 平台改为Win32在VC++ Directories里面，
头文件路径增加：D:\sdk\vs2013\openssl-OpenSSL_1_1_1\dist\include
库文件路径增加：D:\sdk\vs2013\openssl-OpenSSL_1_1_1\dist\lib
Linker -> Input里面增加：libssl.lib，libcrypto.lib，减少：libeay32MT.lib, ssleay32MT.lib

4.编译Debug/Release Win32
