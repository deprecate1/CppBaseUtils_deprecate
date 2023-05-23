cd build\x64
cmake  -G "Visual Studio 17 2022"  -A x64 ../../

cd build\x86
cmake  -G "Visual Studio 17 2022"  -A Win32  -B build  -DENABLE_MYSQL=ON  ../../



分别打开sln，只需要编译uv项目





cmake -B build -DENABLE_MYSQL=ON
cmake --build build 

