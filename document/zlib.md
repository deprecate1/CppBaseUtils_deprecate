1.编译环境：vs2017

zlib-1.2.11(from http://zlib.net)



2.打开vs2017 x86的命令提示符

	cd D:\sdk\vs2017\zlib-1.2.11\contrib\masmx86
	bld_ml32.bat
	把生成的2个obj拷贝到cd D:\sdk\vs2017\zlib-1.2.11



3.编译

	cd D:\sdk\vs2017\zlib-1.2.11
	nmake -f win32/Makefile.msc LOC="-DASMV -DASMINF" OBJA="inffas32.obj match686.obj" 

