

vs2015的控制台运行

cd D:\sdk\vs2015-x86\tiff-4.0.10

nmake /f  makefile.vc



================================

vs2010编译的时候lib可以编译ok，但是测试程序失败，打开makefile.vc，找到：

all:	port lib tools

把tools删掉即可

