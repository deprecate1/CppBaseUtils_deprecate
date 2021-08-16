@echo off
set http_proxy=http://127.0.0.1:1080
set https_proxy=http://127.0.0.1:1080
set opencv_dir="D:/sdk/vs2019/opencv-4.5.3"

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build\vcvars32.bat"

mkdir %opencv_dir%/build/              2> NUL
mkdir %opencv_dir%/build/cpu_win32/    2> NUL
cd /d %opencv_dir%/build/cpu_win32/
pwd

::remove: python, java, test, perf, protobuf
::enable: examples, freetype, nonfree
cmake  -G "Visual Studio 16 2019" -A Win32  ^
    -DBUILD_opencv_python_tests=OFF ^
    -DBUILD_opencv_python_bindings_generator=OFF ^
    -DBUILD_JAVA=OFF ^
    -DBUILD_opencv_java_bindings_generator=OFF ^
    -DBUILD_TESTS=OFF ^
    -DBUILD_PERF_TESTS=OFF ^
    -DINSTALL_C_EXAMPLES=ON ^
    -DBUILD_EXAMPLES=ON ^
    -DWITH_FREETYPE=ON ^
    -DOPENCV_ENABLE_NONFREE=ON ^
    -DOPENCV_EXTRA_MODULES_PATH=%opencv_dir%/opencv_contrib-4.5.3/modules ^
    -DENABLE_PRECOMPILED_HEADERS=OFF ^
    -DBUILD_PROTOBUF=OFF ^
    -DWITH_PROTOBUF=ON ^
    ./../../ 

msbuild ZERO_CHECK.vcxproj   /p:Configuration=Debug
msbuild ALL_BUILD.vcxproj    /p:Configuration=Debug
msbuild INSTALL.vcxproj      /p:Configuration=Debug

msbuild ZERO_CHECK.vcxproj   /p:Configuration=Release
msbuild ALL_BUILD.vcxproj    /p:Configuration=Release
msbuild INSTALL.vcxproj      /p:Configuration=Release

pause
