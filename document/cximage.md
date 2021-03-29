最新版本702：

https://sourceforge.net/projects/cximage



vs2019打开CxImageFull_vc10.sln，修改：



（1）.\CxImage\stdint.h

//typedef int16_t   int_fast16_t;			// vs2019里面这个注释掉，107行
typedef int32_t   int_fast32_t;
typedef int64_t   int_fast64_t;
typedef uint8_t   uint_fast8_t;
//typedef uint16_t  uint_fast16_t;		// vs2019里面这个注释掉



（2）cximagemfcdll 项目属性，链接器，输入库：

```
$(OutDir)png.lib 改为 ..\..\Debug\png.lib 或者  ..\..\Release\png.lib
```

后面的雷同





除了demo和demodll之外的都编译，子项目的依赖没有做好，需要编译2次



使用说明：

https://www.codeproject.com/Articles/1300/CxImage

- CxImage : *cximage.lib* - static library
- CxImageCrtDll : *cximagecrt.dll* - DLL not using mfc
- CxImageMfcDll : *cximage.dll* - DLL using mfc
- Demo : *demo.exe* - program linked with *cximage.lib* and the C libraries
- DemoDll : *demodll.exe* - program linked with *cximagecrt.dll*
- libdcr,jasper,jbig,jpeg,png,tiff,zlib : static C libraries



测试只有CxImageCrtDll 可以用

