
1.依赖boost，且需要安装cmake

2.下载
==========
	mongo-c-driver-1.6.1:    https://github.com/mongodb/mongo-c-driver/releases
	mongo-cxx-driver-r3.1.1: https://github.com/mongodb/mongo-cxx-driver/releases
	libbson-1.6.1: https://github.com/mongodb/libbson/releases


3.参考文章：<br>
https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/installation/<br>
http://www.cnblogs.com/oloroso/p/5740431.html



4.编译（64位用注释的行替代）<br>

	cd D:\sdk\2013\libbson-1.6.1
	mkdir dist_release & cd dist_release
	cmake .. -DCMAKE_INSTALL_PREFIX=./dist -G "Visual Studio 12"
	//cmake .. -DCMAKE_INSTALL_PREFIX=./dist -G "Visual Studio 12 2013 Win64"
	msbuild ALL_BUILD.vcxproj /p:Configuration=Release
	msbuild INSTALL.vcxproj /p:Configuration=Release

	cd ..
	mkdir dist_debug & cd dist_debug
	cmake .. -DCMAKE_INSTALL_PREFIX=./dist -G "Visual Studio 12"
	//cmake .. -DCMAKE_INSTALL_PREFIX=./dist -G "Visual Studio 12 2013 Win64"
	msbuild ALL_BUILD.vcxproj /p:Configuration=Debug
	msbuild INSTALL.vcxproj /p:Configuration=Debug

	=========================================

	cd D:\sdk\2013\mongo-c-driver-1.6.1
	mkdir dist_release & cd dist_release
	cmake .. -DCMAKE_INSTALL_PREFIX=./dist -DBSON_ROOT_DIR=../libbson-1.6.1/dist_release/dist     -G "Visual Studio 12"
	//cmake .. -DCMAKE_INSTALL_PREFIX=./dist -DBSON_ROOT_DIR=../libbson-1.6.1-64/dist_release/dist  -G "Visual Studio 12 2013 Win64"
	msbuild ALL_BUILD.vcxproj /p:Configuration=Release
	msbuild INSTALL.vcxproj /p:Configuration=Release


	cd ..
	mkdir dist_debug & cd dist_debug
	cmake .. -DCMAKE_INSTALL_PREFIX=./dist -DBSON_ROOT_DIR=../libbson-1.6.1/dist_debug/dist     -G "Visual Studio 12"
	//cmake .. -DCMAKE_INSTALL_PREFIX=./dist -DBSON_ROOT_DIR=../libbson-1.6.1-64/dist_debug/dist  -G "Visual Studio 12 2013 Win64"
	msbuild ALL_BUILD.vcxproj /p:Configuration=Debug
	msbuild INSTALL.vcxproj /p:Configuration=Debug

5.mongo-cxx-driver最低要求vs2015update1，暂不使用
