

vs2015的控制台运行

cd D:\sdk\vs2015-x86\jpeg-9c

NMAKE /f makefile.vs  setup-v15

vs2015打开jpeg.sln，平台工具集改为vc140，编译（只有release）



======================================================



vs2010的控制台运行（vs2010能支持的最高版本貌似是jpeg-9b，之后的无法生成工程）

cd D:\test\pdfmate\3rd\jpeg-9b

NMAKE /f makefile.vs  setup-v10

为毛生成的jpeg.sln和jpeg.vcxproj文件最前面多了几个乱码，用ultraedit删掉。

vs2010打开jpeg.sln，编译（只有release）



