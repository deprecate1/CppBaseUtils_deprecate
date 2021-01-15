编译opencv4.5.1(win10, visual studio 2019, cpu&gpu, win32&x64)
---
1.开发环境
vs2017或vs2019或其它版本
cmake-3.18或更高版本

2.解压opencv &contrib &extra
D:\sdk\vs2019\opencv-4.5.1
D:\sdk\vs2019\opencv-4.5.1\opencv_contrib-4.5.1
D:\sdk\vs2019\opencv-4.5.1\opencv_extra-4.5.1

3.configure或者generate都需要下载第三方文件，文件国内无法下载。
(1)如果不想用代理，报错后看CMakeDownloadLog.txt里面的错误信息，然后下载到D:\sdk\vs2019\opencv-4.5.1\ .cache文件夹中；
(2)如果用代理【shadowsocks设置为全局模式】，命令行执行下面3个指令：
set http_proxy=http://127.0.0.1:1080
set https_proxy=http://127.0.0.1:1080
"C:\Program Files\CMake\bin\cmake-gui.exe"

4.cmake基础配置
最上面的两行编辑栏"where is the source code" 和 "where to build the binaries" 分别填写：
D:\sdk\vs2019\opencv-4.5.1
D:\sdk\vs2019\opencv-4.5.1\build\win32-cpu
D:\sdk\vs2019\opencv-4.5.1\build\win32-gpu
D:\sdk\vs2019\opencv-4.5.1\build\x64-cpu              主要用这个调试
D:\sdk\vs2019\opencv-4.5.1\build\x64-gpu
设置完后，点“Configure”按钮，选择编译器比如"Visual Studio 15 2019”，选择win32还是x64

5.cpu版本的cmake参数配置
去掉包含cu,python的，去掉WITH_OPENMP
增加：BUILD_EXAMPLES, INSTALL_C_EXAMPLES, WITH_TBB，WITH_FREETYPE
增加： OPENCV_ENABLE_NONFREE
OPENCV_EXTRA_MODULES_PATH 值设置为 D:/sdk/vs2019/opencv-4.5.1/opencv_contrib-4.5.1/modules
设置完后，点“Generate”按钮


6.gpu版本的cmake参数配置
先安装cuda/cudnn（cudnn安装：解压到cuda安装目录即可：C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v10.0）
测试：打开命令行输入nvcc --version
cufft, npps, nvblas等库只有x64版本，所以opencv-gpu只能编译64位的
和cpu版本不同：打开所有包含cu的选项








编译opencv2.4.13(win10, visual studio 2015)
---

- 源代码解压到D:\sdk\opencv2413
- cmake配置‘source code’和‘build the binaries’路径：
- D:/sdk/opencv2413/sources
- D:/sdk/opencv2413/sources/newbuild
- cmake-gui上点Configure(有个警告可以不用管)
- cmake-gui上点‘Add Entry’，添加CMAKE_GENERATOR_TOOLSET，类型STRING，值v140_xp；去掉BUILD_SHARED_LIBS；这一步不要做了
- cmake去掉：cuda，cufft 
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
