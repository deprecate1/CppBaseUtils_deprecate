vs2013编译protobuf3.3.0
===
	解压protobuf-3.3.0.zip到  D:\sdk\2013
	安装cmake-3.8.1或更高版本

编译release/debug版本
===
	cd D:\sdk\2013\protobuf-3.3.0\cmake
	mkdir release & cd release
	cmake -G "NMake Makefiles" -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./install -Dprotobuf_BUILD_SHARED_LIBS=ON ..
	nmake
	nmake install

	cd D:\sdk\2013\protobuf-3.3.0\cmake
	mkdir debug & cd debug
	cmake -G "NMake Makefiles" -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Debug   -DCMAKE_INSTALL_PREFIX=./install -Dprotobuf_BUILD_SHARED_LIBS=ON ..
	nmake
	nmake install


使用说明
===
	注释MFC冲定义的new
	//#ifdef _DEBUG
	//#define new DEBUG_NEW
	//#endif

	visual studio会误报内存泄漏，用vld(visual leak detect)可以看出来没有
