在freetype源码文件夹中，进入builds\windows，把vs2010复制为vs2015

然后用vs2015打开里面的sln编译，编译win32的Debug&Release



由于里面的平台工具集是：$(DefaultPlatformToolset)

所以不需要再改visual studio配置了，非常方便