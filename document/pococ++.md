有属性表文件，在props文件夹下

编译过程
====
打开cmake-gui，填写：
D:/sdk/vs2017-x86/poco-poco-1.9.0-release
D:/sdk/vs2017-x86/poco-poco-1.9.0-release/mybuild

点击Configure按钮，然后配置：
CMAKE_INSTALL_PREFIX	填写D:/sdk/vs2017-x86/poco-poco-1.9.0-release/mybuild/install
以下打钩：
ENABLE_CPPPARSER
ENABLE_SEVENZIP
以下去掉打钩：
含SSL, MYSQL的全部去掉


然后点Generate，然后批量编译ALL_BUILD(Win32 Debug/Release)，然后批量编译INSTALL(Win32 Debug/Release)

