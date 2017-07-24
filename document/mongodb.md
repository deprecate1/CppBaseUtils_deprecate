
1.依赖boost，且需要安装cmake

2.下载
==========
	mongo-c-driver-1.6.1:    https://github.com/mongodb/mongo-c-driver/releases
	mongo-cxx-driver-r3.1.1: https://github.com/mongodb/mongo-cxx-driver/releases
	libbson-1.6.1: https://github.com/mongodb/libbson/releases


3.参考文章：<br>
https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/installation/<br>
http://www.cnblogs.com/oloroso/p/5740431.html



4.编译mongo-c-driver<br>
libbson解压到D:\sdk\2013\mongo-c-driver-1.6.1\src\libbson


	cd D:\sdk\2013\libbson-1.6.1
	cmake -DCMAKE_INSTALL_PREFIX=D:\sdk\2013\libbson-1.6.1\dist -G "Visual Studio 12"
	msbuild ALL_BUILD.vcxproj
	msbuild INSTALL.vcxproj
	（上面的CMAKE_INSTALL_PREFIX必须有，否则debug覆盖release）

	cd D:\sdk\2013\mongo-c-driver-1.6.1
	cmake -DCMAKE_INSTALL_PREFIX=D:\sdk\2013\mongo-c-driver-1.6.1\dist -DBSON_ROOT_DIR=D:\sdk\2013\libbson-1.6.1\dist  -G "Visual Studio 12"  -DENABLE_SSL=OFF
	msbuild ALL_BUILD.vcxproj
	msbuild INSTALL.vcxproj

5.mongo-cxx-driver最低要求vs2015update1，暂不使用
