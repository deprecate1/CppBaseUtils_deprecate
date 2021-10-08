(1)随便找个vs命令行，执行bootstrap.bat（不需要参数），会生成b2.exe



(2.1)网上的（**不要使用**）（https://github.com/boostorg/boost_install/issues/14）：先stage（默认），后install
b2 --prefix=/usr --stagedir=/tmp/boost_stage  stage
b2 --prefix=/tmp/boost_install  install



(2.2)自己的（推荐），因为没有install，可以不要prefix

vs2015是14.0，vs2017是14.1，vs2019是14.2



b2.exe   toolset=msvc-14.2    --prefix=./build/x64-default/prefix      --stagedir=./build/x64-default/stage       --build-dir=./build/x64-default/build
b2.exe   toolset=msvc-14.2    --prefix=./build/x64-static/prefix         --stagedir=./build/x64-static/stage          --build-dir=./build/x64-static/build         link=static   runtime-link=static



b2.exe   toolset=msvc-14.2    --prefix=./build/x86-default/prefix      --stagedir=./build/x86-default/stage       --build-dir=./build/x86-default/build
b2.exe   toolset=msvc-14.2    --prefix=./build/x86-static/prefix         --stagedir=./build/x86-static/stage          --build-dir=./build/x86-static/build        link=static   runtime-link=static



可以删除：

build\x86-default\build

build\x86-static\build

build\x64-default\build

build\x64-static\build



