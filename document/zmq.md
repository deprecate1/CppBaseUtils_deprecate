1.编译环境：vs2013 update5

编译代码：zeromq-4.2.5.tar.gz



2.修改\builds\msvc\vs2015\libzmq.import.props

	把..\..\..\..\..\libzmq\bin 改为 ..\..\..\..\bin



3.把builds\msvc\vs2015中的所有文件拷贝到builds\msvc\vs2013

**libzmq.sln除外**



4.用vs2013打开builds\msvc\vs2013\libzmq.sln

把7个子工程的平台工具集改为vs2013，编译DynDebug和DynRelease两套(win32)



5.props使用，环境变量设置

