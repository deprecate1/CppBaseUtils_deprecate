编译Python-3.5.0.tgz\Python-3.5.0\PCbuild\pcbuild.sln，可以得到python35.dll，
然后在3rd下新建文件夹python，讲python源码下的lib拷贝到这里

	Py_SetPythonHome(python_path);
	Py_Initialize();
	Py_Finalize();
