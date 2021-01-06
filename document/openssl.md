参考这里面的脚本：http://p-nand-q.com/programming/windows/building_openssl_with_visual_studio.html

接口demo：

https://www.codeproject.com/Articles/891444/Building-and-configuring-OpenSSL-in-Visual-Studio
https://www.codeproject.com/Articles/1016357/OpenSSL-Tour-for-Win-Developer

(1)安装ActivePerl-5.26.1.2601-MSWin32-x64-404865.exe和nasm-2.13.03-installer-x64.exe，设置到环境变量

(2)下载openssl-OpenSSL_1_1_1.zip

(3)运行perl --version和nasm -v，如果有问题，后面的没有意义

=====================================================

编译步骤

=====================================================

打开“VS2013 x86/x64 本机工具命令提示符”或者“VS2019 x86/x64 本机工具命令提示符” 

cd D:\sdk\vs201x\openssl-OpenSSL_1_1_1

说明：老版本的openssl需要执行ms\do_ms.bat脚本，现在1.1.x不需要了文件也被删除了

注意：下面的prefix最好加上，openssl文件组织实在太乱了

说明：perl Configure可能报错：打开C:\Perl64\site\lib\ActivePerl\Config.pm 找到_warn函数，大约在394行，把里面的全部注释掉

	perl Configure VC-WIN32 --prefix=D:\sdk\vs2019\openssl-OpenSSL_1_1_1i\dist-win32
	nmake
	nmake install_sw
	nmake distclean


	perl Configure  VC-WIN64A  --prefix=D:\sdk\vs2019\openssl-OpenSSL_1_1_1i\dist-x64
	nmake
	nmake install_sw
	nmake distclean




makefile 里面还可以：nmake install_ssldirs ，但是目前没有用到

注意：openssl 1.1.0开始由原先的libeay32.dll、ssleay32.dll变成了libcrypto-1_1.dll、libssl-1_1.dll，一些加密方式也发生了变化















=====================================================

vs2010编译openssl-1.0.1c步骤：

=====================================================

参考：https://www.cnblogs.com/godboy1989/p/4064420.html

具体如下：

d:

cd D:\sdk\vs2010-x86\openssl-OpenSSL_1_0_1c

mkdir dist

perl Configure VC-WIN32 --prefix=D:\sdk\vs2010\openssl-OpenSSL_1_1_1\dist

输入**ms\do_nasm回车**

然后：

生成动态库使用  nmake -f ms\ntdll.mak             建议用动态库

生成静态库使用  nmake -f ms\nt.mak                 不推荐！



