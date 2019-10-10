修改libpng-1.6.37\projects\vstudio\zlib.props

找到ZLibSrcDir，改为已经编译成功的zlib路径，如下：

<ZLibSrcDir>D:\test\pdfmate\3rd\zlib-1.2.5</ZLibSrcDir>



然后打开：libpng-1.6.37\projects\vstudio\vstudio.sln

编译libpng的debug和release，如果有编译错误，把项目属性的‘将警告视为错误’关闭即可



vs2010和vs2015测试ok

