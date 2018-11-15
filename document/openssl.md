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

打开“VS2013 x86 本机工具命令提示符”或者“VS2017 x86 本机工具命令提示符” ，可以管理员身份运行

cd D:\sdk\2013\openssl-OpenSSL_1_1_1

说明：老版本的openssl需要执行ms\do_ms.bat脚本，现在1.1.x不需要了文件也被删除了


注意：下面的prefix最好加上，openssl文件组织实在太乱了

	perl Configure VC-WIN32 --prefix=D:\sdk\vs2013\openssl-OpenSSL_1_1_1\dist
	nmake
	nmake test（时间较长可以不做）
	nmake install             ★★★命令行需要管理员权限★★★
