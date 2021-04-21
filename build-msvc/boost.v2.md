(1)随便找个vs命令行，执行bootstrap.bat（不需要参数），会生成b2.exe



(2.1)网上的（**不要使用**）（https://github.com/boostorg/boost_install/issues/14）：先stage（默认），后install
b2 --prefix=/usr --stagedir=/tmp/boost_stage  stage
b2 --prefix=/tmp/boost_install  install



(2.2)自己的（推荐），因为没有install，可以不要prefix

vs2015是14.0，vs2017是14.1，vs2019是14.2



b2.exe   toolset=msvc-14.2   --prefix=./build/default-win32/prefix  --stagedir=./build/default-win32/stage   --build-dir=./build/default-win32/build

b2.exe   toolset=msvc-14.2   --prefix=./build/static-win32/prefix     --stagedir=./build/static-win32/stage      --build-dir=./build/static-win32/build     link=static   runtime-link=static

b2.exe   toolset=msvc-14.2   --prefix=./build/default-x64/prefix      --stagedir=./build/default-x64/stage       --build-dir=./build/default-x64/build

b2.exe   toolset=msvc-14.2   --prefix=./build/static-x64/prefix         --stagedir=./build/static-x64/stage          --build-dir=./build/static-x64/build         link=static   runtime-link=static

