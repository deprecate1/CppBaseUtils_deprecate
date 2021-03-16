最新版本702：

https://sourceforge.net/projects/cximage



修改：



（1）.\CxImage\stdint.h

//typedef int16_t   int_fast16_t;			// vs2019里面这个注释掉
typedef int32_t   int_fast32_t;
typedef int64_t   int_fast64_t;
typedef uint8_t   uint_fast8_t;
//typedef uint16_t  uint_fast16_t;		// vs2019里面这个注释掉



（2）cximagemfcdll属性，链接器，输入库：

$(OutDir)png.lib 改为 ..\..\Debug\png.lib 或者  ..\..\Release\png.lib

后面的雷同





除了demodll项目都编译



使用说明：

https://www.codeproject.com/Articles/1300/CxImage

- CxImage : *cximage.lib* - static library
- CxImageCrtDll : *cximagecrt.dll* - DLL not using mfc
- CxImageMfcDll : *cximage.dll* - DLL using mfc
- Demo : *demo.exe* - program linked with *cximage.lib* and the C libraries
- DemoDll : *demodll.exe* - program linked with *cximagecrt.dll*
- libdcr,jasper,jbig,jpeg,png,tiff,zlib : static C libraries