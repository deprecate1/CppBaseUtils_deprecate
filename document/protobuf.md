vs2015编译protobuf2.6.1
===
- 解压protobuf-2.6.1.zip到  D:\sdk
- 打开vsprojects/protobuf.sln
- 编辑vsprojects/config.h，最上面添加#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
- 批生成libprotobuf, libprotobuf-lite, libprotoc, protoc（Debug/Relase）
- 使用请参考属性表文件，目标工程用32位，protobuf不生成64位库
