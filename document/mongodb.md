x86, x64的debug,release分别编译（总共4次编译），注意在vcvarsall.bat下运行

过程

	*********************************************
	编译x86的debug和reelase

	cd D:\sdk\2013\mongo-c-driver-1.11.0-x86

	mkdir dist-release
	cd dist-release
	cmake .. -DCMAKE_INSTALL_PREFIX=./ -G "Visual Studio 12"
	msbuild ALL_BUILD.vcxproj /p:Configuration=Release
	msbuild INSTALL.vcxproj /p:Configuration=Release

	cd ..
	mkdir dist-debug
	cd dist-debug
	cmake .. -DCMAKE_INSTALL_PREFIX=./ -G "Visual Studio 12"
	msbuild ALL_BUILD.vcxproj /p:Configuration=Debug
	msbuild INSTALL.vcxproj /p:Configuration=Debug

	*********************************************
	编译x64
	cd D:\sdk\2013\mongo-c-driver-1.11.0-x64
	把"Visual Studio 12" 改为："Visual Studio 12 2013 Win64"

