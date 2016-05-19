compile bcg22 for visual studio 2015
===
	下载‘Bcg_V22.1_直接next_不用输入key.exe’网上很好找。
	(1)安装，直接next，全部默认。
	(2)安装好的bcg在：C:\Program Files (x86)\BCGSoft\BCGControlBarPro，（win10的话把文件夹属性改成可读可写，默认可读不可写）
	(3)修改：BCGCBProConfig.h, 找到‘_MSC_VER == 1800’，这是visual studio 2013分支，复制到#else里面（替代错误的那一行）
	(4)执行BCGCBPro120.sln，项目属性，把unicode debug和unicode release的平台工具集
		‘Visual Studio 2015 (v140)’改为：‘Visual Studio 2015 - Windows XP (v140_xp)’，以便支持winxp
	(5)批生成里面编译这2个平台，可以看到如下成功信息：

	正在创建库 ..\bin/BCGCBPRO2210u120.lib 和对象 ..\bin/BCGCBPRO2210u120.exp
	BCGCBPro120.vcxproj -> C:\Program Files (x86)\BCGSoft\BCGControlBarPro\BCGCBPro\..\bin\BCGCBPRO2210u120.dll
	
	正在创建库 ..\bin/BCGCBPRO2210ud120.lib 和对象 ..\bin/BCGCBPRO2210ud120.exp
	BCGCBPro120.vcxproj -> C:\Program Files (x86)\BCGSoft\BCGControlBarPro\BCGCBPro\..\bin\BCGCBPRO2210ud120.dll
	
	(6)把BCGCBPRO2210u120.dll和BCGCBPRO2210ud120.dll拷贝到c:\windows下面


属性表
===
见props文件夹下bcgcbpro22.props，以后新建bcg工程不必每次配置include/lib


测试
===

