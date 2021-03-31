老版本-1.4.3

http://crashrpt.sourceforge.net/



新版本1.5.0

https://github.com/QbProg/crashrpt2



**这2个版本的编译方法都一样**

1.打开cmake-gui，然后source和build选择

D:/sdk/vs2019/crashrpt2-master-2020.08.25

D:/sdk/vs2019/crashrpt2-master-2020.08.25/build/win32

D:/sdk/vs2019/crashrpt2-master-2020.08.25/build/x64

点configure按钮，选择vs2015或者其它版本，再点generate按钮，然后visual studio打开sln文件编译debug&release版本



**集成需要的文件，多语言等**

编译时用props文件，并至少集成二进制文件：CrashRpt1500.dll，CrashSender1500.exe, dbghelp.dll，必须集成语言文件crashrpt_lang.ini，否则报错（可以通过crGetLastErrorMsg得到信息）



dbghelp.dll：虽然一般os集成了，但crashrpt帮助文档中建议也集成二进制文件：

C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\IDE\Extensions\TestPlatform\Extensions\Cpp

或者

C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\Extensions\TestPlatform\Extensions\Cpp