https://github.com/mackyle/sqlite    截止2020.8.25最新版本是：sqlite-version-3.33.0

要先安装tcl8.6，参考README.md折腾了一会还是不行

**放弃**



======================================================================

**建议用下面的方法编译**

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

