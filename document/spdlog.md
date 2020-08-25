spdlog有几种使用方式：包含头文件形式，或者编译成dll库



如果是头文件形式，spdlog里面的全局变量会被编译器内化，在dll中会得不到主程序注册的对象，虽然地址空间是同一个，但是各有各的data section。

除非在exe模块中把spdlog的对象全部export。visual studio编译器不知道怎么做，或者不支持。

[头文件方式需要在dll中增加接口](https://github.com/gabime/spdlog/wiki/How-to-use-spdlog-in-DLLs)





cmake编译：win32和x64



