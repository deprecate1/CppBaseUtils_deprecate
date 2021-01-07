从官网下载 https://www.sqlite.org/download.html     文件：sqlite-src-3340000.zip（文件大约12MB）

安装ActiveTcl-8.6，接下来编译步骤参考里面的README.md

打开“VS2013 x86/x64 本机工具命令提示符”或者“VS2019 x86/x64 本机工具命令提示符” 

cd D:\sdk\vs2019\sqlite-src-3340000\

mkdir  build_Win32  build_x64

nmake /f ..\Makefile.msc TOP=..\                        // x86/x64分别执行







======================================================================

**老的编译方法（不再推荐）**

======================================================================

参考：https://my.oschina.net/u/4296574/blog/4275395

从官网下载 https://www.sqlite.org/download.html  下载zip后缀，不要下tar.gz的

新建“动态链接库（DLL）”项目，名称比如project，把文件全删除，添加：sqlite3.h sqlite3.c sqlite3.def



去掉预编译头，预处理添加：

SQLITE_ENABLE_RTREE

SQLITE_ENABLE_COLUMN_METADATA

SQLITE_ENABLE_FTS3

SQLITE_ENABLE_FTS5

SQLITE_ENABLE_DESERIALIZE

添加模块定义文件 sqlite3.def

后面都参考https://my.oschina.net/u/4296574/blog/4275395



