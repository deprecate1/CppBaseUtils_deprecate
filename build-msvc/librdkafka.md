1.�ο����£�librdkafka-0.11.6\README.win32

2.ע�⣺openssl����github�ϵİ汾��OpenSSL_1_1_1
���뷽����openssl

3.�����vs2017��vs2013����Ҫ������裩����librdkafka-0.11.6\win32\librdkafka.vcxproj����������ImportGroup��Target�ֶ�ɾ��

4.��vs2013��vs2017����Ҫ�����򿪹��̣���librdkafka�����ã�ѡ���ΪAll Configurations, ƽ̨��ΪWin32��VC++ Directories���棬
ͷ�ļ�·�����ӣ�
?		D:\sdk\vs2013-x86\openssl-OpenSSL_1_1_1\dist\include

?		D:\sdk\vs2017-x86\openssl-OpenSSL_1_1_1\dist\include

���ļ�·�����ӣ�
?		D:\sdk\vs2013-x86\openssl-OpenSSL_1_1_1\dist\lib

?		D:\sdk\vs2017-x86\openssl-OpenSSL_1_1_1\dist\lib
Linker -> Input�������ӣ�libssl.lib��libcrypto.lib�����٣�libeay32MT.lib, ssleay32MT.lib

5.vs2017����Ҫ��ͷ�ļ��Ϳ��ļ�·�����ӣ�D:\sdk\vs2017-x86\zlib-1.2.11�����������ӣ�zdll.lib����Ҫʹ��zlib.lib

6.����librdkafka��librdkafkacpp��Debug/Release��ƽ̨��Win32

