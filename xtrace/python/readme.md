
未测试，稍后修改：
	
	# test on python-2.7.3
	from ctypes import *
	
	# load it
	mydll=windll.LoadLibrary("c:\\xtrace.dll")
	
	# function has to be extern "C" and have an undecorated name:
	XTRACE=mydll.MagicTraceProc
	XTRACE(1, 0x0000ff, "abcdefg1\n", 0, 0)
	XTRACE(1, 0x00ff00, "abcdefg2\n", 0, 0)
	XTRACE(1, 0xff0000, "abcdefg3\n", 0, 0)
	raw_input("press enter to exit test")
