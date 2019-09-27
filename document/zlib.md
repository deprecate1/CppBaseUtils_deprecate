vs2015编译

用vs2015打开D:\sdk\vs2015-x86\zlib-1.2.11\contrib\vstudio\vc14\zlibvc.sln

修改子项目zlibvc的属性：链接器 -> 高级 -> 映像具有安全异常属性：**改为否**

只需要编译子项目zlibvc的win32平台的Debug&Release



=========================================================





1.编译环境：vs2017

zlib-1.2.11(from http://zlib.net)



2.打开vs2017 x86的命令提示符

	cd D:\sdk\vs2017\zlib-1.2.11\contrib\masmx86
	bld_ml32.bat
	把生成的2个obj拷贝到cd D:\sdk\vs2017\zlib-1.2.11



3.编译

	cd D:\sdk\vs2017\zlib-1.2.11
	nmake -f win32/Makefile.msc LOC="-DASMV -DASMINF" OBJA="inffas32.obj match686.obj" 

