spdlog有几种使用方式：包含头文件形式，或者编译成dll库



如果是头文件形式，spdlog里面的全局变量会被编译器内化，在dll中会得不到主程序注册的对象，虽然地址空间是同一个，但是各有各的data section。

除非在exe模块中把spdlog的对象全部export。visual studio编译器不知道怎么做，或者不支持。



解决方法：spdlog-1.4.0以后的版本支持编译dll方式

cd D:\sdk\vs2015-x86\spdlog-1.4.2

mkdir build && cd build

cmake .. -DCMAKE_BUILD_TYPE=shared -G "Visual Studio 14 2015"

然后用vs2015打开sln文件编译



附props文件

