
1.下载
===
cmake：http://www.cmake.org/cmake/resources/software.html

最新版本是cmake-3.5.2-win32-x86.msi

2.libcef网站
===
https://cefbuilds.com/，现在的最新版是Branch 2623，下载大小112M

3.运行cmake
===
参考：http://blog.jianchihu.net/libcef-build-use.html

4.编译
===
生成了cef.sln，用visual studio 2015打开，把平台工具集改为‘Visual Studio 2015 - Windows XP (v140_xp)’

修改：cefclient项目，右键点属性->配置属性->c/c++->常规，将“警告视为错误”的选项改为“否”

编译生成所有

5.属性表文件
===
参考props文件夹
