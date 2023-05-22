@echo off
set boost_dir="D:/sdk/props_build_vs2022/boost_1_82_0"

cd /d %boost_dir%
call "bootstrap.bat"

call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat"
b2.exe   toolset=msvc-14.3    --prefix=./build/x64-default/prefix      --stagedir=./build/x64-default/stage       --build-dir=./build/x64-default/build
b2.exe   toolset=msvc-14.3    --prefix=./build/x64-static/prefix       --stagedir=./build/x64-static/stage        --build-dir=./build/x64-static/build         link=static   runtime-link=static

call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars32.bat"
b2.exe   toolset=msvc-14.3    --prefix=./build/x86-default/prefix      --stagedir=./build/x86-default/stage       --build-dir=./build/x86-default/build
b2.exe   toolset=msvc-14.3    --prefix=./build/x86-static/prefix       --stagedir=./build/x86-static/stage        --build-dir=./build/x86-static/build         link=static   runtime-link=static

rm  -fr  .\build\x86-default\build\
rm  -fr  .\build\x86-static\build\
rm  -fr  .\build\x64-default\build\
rm  -fr  .\build\x64-static\build\

pause
