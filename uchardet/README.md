说明
=====================
CharsetDetectDemo 文件夹是visual studio 2015的demo(vc mfc dialog project)

用法：集成uchardet文件夹下的.h和.cpp，以及EncodingMapper.h/EncodingMapper.cpp  (这2个文件是壳)到工程。

uchardet来自notepad++，仅做了微量改动

demo
=====================


	#include "../../uchardet/uchardet.h"
	#include "../../EncodingMapper.h"
	int CCharsetDetectDemoDlg::detectCodepage(char* buf, size_t len)
	{
		uchardet_t ud = uchardet_new();
		uchardet_handle_data(ud, buf, len);
		uchardet_data_end(ud);
		const char* cs = uchardet_get_charset(ud);
		int codepage = EncodingMapper::getInstance()->getEncodingFromString(cs);
		uchardet_delete(ud);
		return codepage;
	}
	
	CString CCharsetDetectDemoDlg::detectCodepage2(char* buf, size_t len)
	{
		USES_CONVERSION;
		uchardet_t ud = uchardet_new();
		uchardet_handle_data(ud, buf, len);
		uchardet_data_end(ud);
		const char* cs = uchardet_get_charset(ud);
		CString result = A2W(cs);
		uchardet_delete(ud);
		return result;
	}


输出结果
=====================
	filename: C:\Users\clock\Desktop\1gb2312.txt
	code page: gb18030, 936
	filename: C:\Users\clock\Desktop\2utf8.txt
	code page: UTF-8, 65001
	filename: C:\Users\clock\Desktop\3utf8bom.txt
	code page: UTF-8BOM, 65001
	filename: C:\Users\clock\Desktop\4other.txt
	code page: UTF-16BOM, 65001
