最新版本702：

https://sourceforge.net/projects/cximage



vs2019打开CxImageFull_vc10.sln，修改：



（1）修改.\CxImage\ximadef.h

第96行，#include "stdint.h" 改为 #include <stdint.h>

修改.\CxImage\ximacfg.h，添加一行：
#define CXIMAGE_SUPPORT_ENCODE 1


（2）cximagemfcdll 项目属性，链接器，输入库：

```
$(OutDir)png.lib 改为 ..\..\Debug\png.lib 或者  ..\..\Release\png.lib
```

后面的雷同





这3个项目不需要编译：demo，demodll，cximagemfcdll

**注意：整个工程的子项目的依赖没有做好，需要编译2次**



使用说明：

https://www.codeproject.com/Articles/1300/CxImage

- CxImage : *cximage.lib* - static library
- CxImageCrtDll : *cximagecrt.dll* - DLL not using mfc
- CxImageMfcDll : *cximage.dll* - DLL using mfc
- Demo : *demo.exe* - program linked with *cximage.lib* and the C libraries
- DemoDll : *demodll.exe* - program linked with *cximagecrt.dll*
- libdcr,jasper,jbig,jpeg,png,tiff,zlib : static C libraries


推荐用CxImageCrtDll 

