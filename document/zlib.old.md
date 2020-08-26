

=========================================================

**重要（不管是vs2010还是vs2019都做一下）**

=========================================================

inflate里面的inflate_fast是汇编写的，目前最新版本仍然存在bug，会导致指针异常。

这个函数存在汇编和c语言两个版本，改为强制c语言，去掉zlibvc项目的2个预定义宏：

ASMV

ASMINF

并且把附加依赖项的obj去掉：..\..\masmx86\match686.obj;..\..\masmx86\inffas32.obj;



=========================================================

vs2010编译

直接打开contrib\vstudio\vc10\zlibvc.sln编译zlibvc子项目即可，这个就是vs2010工程

=========================================================

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

=========================================================

