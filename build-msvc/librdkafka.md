1.参考文章：librdkafka-0.11.6\README.win32

2.注意：openssl下载github上的版本：OpenSSL_1_1_1
编译方法见openssl

3.如果是vs2017（vs2013不需要这个步骤），打开librdkafka-0.11.6\win32\librdkafka.vcxproj，把最后面的ImportGroup和Target字段删掉

4.用vs2013和vs2017都需要做：打开工程，打开librdkafka的设置，选项改为All Configurations, 平台改为Win32在VC++ Directories里面，
头文件路径增加：
?		D:\sdk\vs2013-x86\openssl-OpenSSL_1_1_1\dist\include

?		D:\sdk\vs2017-x86\openssl-OpenSSL_1_1_1\dist\include

库文件路径增加：
?		D:\sdk\vs2013-x86\openssl-OpenSSL_1_1_1\dist\lib

?		D:\sdk\vs2017-x86\openssl-OpenSSL_1_1_1\dist\lib
Linker -> Input里面增加：libssl.lib，libcrypto.lib，减少：libeay32MT.lib, ssleay32MT.lib

5.vs2017还需要：头文件和库文件路径增加：D:\sdk\vs2017-x86\zlib-1.2.11；链接器增加：zdll.lib，不要使用zlib.lib

6.编译librdkafka和librdkafkacpp的Debug/Release，平台是Win32

