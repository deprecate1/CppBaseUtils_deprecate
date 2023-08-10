cd build\x64
cmake  -G "Visual Studio 17 2022"  -A x64 ../../    -DBUILD_TESTING=OFF

cd build\x86
cmake  -G "Visual Studio 17 2022"  -A Win32 ../../    -DBUILD_TESTING=OFF



分别打开sln，只需要编译uv项目