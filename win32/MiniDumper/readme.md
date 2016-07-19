在工程中加入MiniDumper.h和MiniDumper.cpp

在程序任何地方加入：


	#include "MiniDumper.h"
	CMiniDumper g_miniDumper(true);


当程序异常后，在可执行文件同级文件夹生成.dmp文件，用visual studio打开可以看到异常堆栈。
debug/release都支持。
