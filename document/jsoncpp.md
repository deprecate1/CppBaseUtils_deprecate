https://github.com/open-source-parsers/jsoncpp



编译过程
====
打开cmake-gui，填写：
D:/sdk/vs2019-x86/jsoncpp-1.9.3

D:/sdk/vs2019-x86/jsoncpp-1.9.3/mybuild

点击Configure按钮，然后配置："visual studio 16 2019"，平台选择“win32"

配置：

| BUILD_SHARED_LIBS  | 打钩     |      |
| ------------------ | -------- | ---- |
| BUILD_TESTING      | 去掉打钩 |      |
| JSONCPP_WITH_TESTS | 去掉打钩 |      |
|                    |          |      |

然后点Generate，然后批量编译ALL_BUILD(Win32 Debug/Release)

