vs2015编译版本2.6.1
===
- 解压protobuf-2.6.1.zip到  D:\sdk
- 打开vsprojects/protobuf.sln
- 编辑vsprojects/config.h，最上面添加#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
- 批生产libprotobuf, libprotobuf-lite, libprotoc, protoc（Debug/Relase）
- xxxx
