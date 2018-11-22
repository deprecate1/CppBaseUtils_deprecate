

编译opencv2.4.13(win10, visual studio 2015)
---
- 源代码解压到D:\sdk\opencv2413
- cmake配置‘source code’和‘build the binaries’路径：
- D:/sdk/opencv2413/sources
- D:/sdk/opencv2413/sources/newbuild
- cmake-gui上点Configure(有个警告可以不用管)
- cmake-gui上点‘Add Entry’，添加CMAKE_GENERATOR_TOOLSET，类型STRING，值v140_xp；去掉BUILD_SHARED_LIBS
- cmake-gui上点Generate生成OpenCV.sln
- 打开:D:\sdk\opencv2413\sources\newbuild\OpenCV.sln，批生成全部


编译opencv3.1.0（未完全测试，请勿参考）
---
- 环境是win10, opencv 3.1.0,visual studio 2015
- cmake配置‘source code’和‘build the binaries’路径：
- D:/sdk/opencv310/sources
- D:/sdk/opencv310/sources/newbuild
- cmake-gui上点Configure
- cmake-gui上点‘Add Entry’，添加CMAKE_GENERATOR_TOOLSET，类型STRING，值v140_xp；去掉BUILD_SHARED_LIBS
- cmake-gui上点Generate生成OpenCV.sln
- 打开:D:\sdk\opencv310\sources\newbuild\OpenCV.sln，批生成全部


属性表
---
参考props/opencv310_xx.props, props/opencv2413_xx.props
