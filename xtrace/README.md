说明
=================
(1)只能运行在windows平台

(2)支持多语言，不依赖任何库


原理
=================
XTraceMonitor.exe启动时初始化共享内存，并在windows 临时文件夹产生临时xtrace.dll；当运行到xtrace语句时，加载xtrace.dll和共享内存通信。


c++用法
=================
	#include "xtrace.h"
	xtrace(L"hello, world.\n");
	xtrace(L"string: %s, int: %d\n", L"hello", 12345);

c#用法
=================

golang用法
=================

python用法
=================

lua用法
=================

ruby用法
=================

