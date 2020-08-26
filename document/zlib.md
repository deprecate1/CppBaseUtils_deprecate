

vs2010编译

打开contrib\vstudio\vc10\zlibvc.sln

=========================================================

vs2015/2017编译

打开contrib\vstudio\vc14\zlibvc.sln

=========================================================

只需要编译子项目zlibvc

=========================================================

修改子项目zlibvc的属性：链接器 -> 高级 -> 映像具有安全异常属性：**改为否**

编译子项目zlibvc的win32/x64平台的Debug&Release。生成zlibwapi.dll

x64的debug可能编译不过，修改zlibvc.vcxproj把bld_ml64.bat路径改对就行了



注意： zlibwapi需要定义宏ZLIB_WINAPI



说明：

还有个编译zlib1.dll的，使用nmake编译。zlib1.dll和zlibwapi.dll都是官网支持的，推荐后者