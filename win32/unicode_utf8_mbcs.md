
unicode/utf8/mbcs：

	void UnicodeToUtf8(const TCHAR *unicode, char *utf8)
	{
		int len = WideCharToMultiByte(CP_UTF8, 0, (const TCHAR *)unicode, -1, NULL, 0, NULL, NULL);
	
		memset(utf8, 0, len * 2 + 2);
		WideCharToMultiByte(CP_UTF8, 0, (const TCHAR *)unicode, -1, utf8, len, NULL, NULL);
	}
	
	void Utf8ToUnicode(const char *utf8, TCHAR *unicode)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, (const char *)utf8, -1, NULL, 0);
	
		MultiByteToWideChar(CP_UTF8, NULL, utf8, -1, unicode, len);
	}

