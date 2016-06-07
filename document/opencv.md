编译opencv3.1.0
---
- 环境是win10, opencv 3.1.0,visual studio 2015
- cmake配置‘source code’和‘build the binaries’路径：
- D:/sdk/opencv310/sources
- D:/sdk/opencv310/sources/newbuild
- 打开:D:\sdk\opencv310\sources\newbuild\OpenCV.sln
- <PlatformToolset>v140</PlatformToolset>改为<PlatformToolset>v140_xp</PlatformToolset>
- CMAKE_GENERATOR_TOOLSET=v140_xp


属性表
---
参考props/opencv310_xx.props, props/opencv2413_xx.props
