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

vs2019打开 .\VisualMagick\VisualStaticMTD.sln **只编译Release**

(3)64位

选择：“Dynamic Multi-threaded DLL runtimes"（默认的也是这个），并选择"64bit", 其它默认

vs2019打开 .\VisualMagick\VisualStaticMTD.sln **只编译Release**



3.属性表



==================

发布时，拷贝dll：

