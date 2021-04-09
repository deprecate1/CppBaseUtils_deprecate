参考：http://www.imagemagick.org/script/install-source.php#windows



1.下载源码，有2种方法

(1) git方式

```
git clone https://github.com/ImageMagick/ImageMagick-Windows.git ImageMagick-Windows-7
cd ImageMagick-Windows-7
CloneRepositories.cmd
```

(2) 网站下载源码包，**推荐这种方法下载**

https://download.imagemagick.org/ImageMagick/download/windows/

下载那个一百多兆的：ImageMagick-windows.zip或者ImageMagick-7.0.11-4.zip（推荐后者，其实是一样的）

（不要下.7z后缀的，这只有核心代码）



2.编译

32位和64位分别编译，创建2个文件夹解压源码到里面

D:\sdk\vs2019\ImageMagick\32

D:\sdk\vs2019\ImageMagick\64



(1)vs2019打开D:\sdk\vs2019\ImageMagick\32\VisualMagick\configure\configure.sln 编译运行

(2)32位

选择：“Dynamic Multi-threaded DLL runtimes"（默认的也是这个），其它默认

vs2019打开 .\VisualMagick\VisualStaticMTD.sln **编译Debug&Release**

(3)64位

选择：“Dynamic Multi-threaded DLL runtimes"（默认的也是这个），并选择"64bit", 其它默认

vs2019打开 .\VisualMagick\VisualStaticMTD.sln **编译Debug&Release**





3.属性表



4.使用

只要#include <Magick++.h>就可以使用所有功能了

```
#include <Magick++.h>
using namespace std;
using namespace Magick;

void test123()
{
	InitializeMagick(NULL);

	Image image;
	try {
		image.read("logo:");
		image.crop(Geometry(100, 100, 100, 100));
		image.write("ImageMagickTest.png");
	} catch (Exception& error_) {
		return;
	}

	TerminateMagick();
	printf("success.\n");
}
```



5.发布时，必须要集成的dll（这几个dll是最基本的）：

```
CORE_RL_bzlib_.dll
CORE_RL_libxml_.dll
CORE_RL_freetype_.dll
CORE_RL_lqr_.dll
CORE_RL_glib_.dll
CORE_RL_zlib_.dll
CORE_RL_lcms_.dll

CORE_RL_MagickWand_.dll
CORE_RL_Magick++_.dll
CORE_RL_MagickCore_.dll
```

比如还要ico转png功能，还需要集成几个dll：

```
IM_MOD_RL_icon_.dll
IM_MOD_RL_png_.dll
CORE_RL_png_.dll
```



6.填坑记录

比如有个文件:   c:\myfile ，这是个ico文件，但是没有后缀，Magick++的接口不支持直接read，会报no codec异常，解决方法：

			Image image;
			image.magick("ICON");
			image.read(Blob(buffer, size));				// 把文件读到内存里面：buffer/size，再用Blob构造
			image.write("c:\\output_to_png_format.png");
