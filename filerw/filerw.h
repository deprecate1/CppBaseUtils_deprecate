#ifndef __FILE_RW_2022_H__
#define __FILE_RW_2022_H__

#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifdef _WIN32
#pragma warning (disable : 4996)
#endif

static std::string readfile(std::string filename)
{
	FILE* fp = fopen(filename.c_str(), "rb");
	if (!fp)
		return "";

	fseek(fp, 0, SEEK_END);
	int fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);  // same as rewind(f);

	char* buf = (char*)malloc(fsize + 1);
	memset(buf, 0x0, fsize + 1);
	fread(buf, 1, fsize, fp);
	fclose(fp);

	return buf;
}

static int writefile(std::string filename, void *buffer, int len)
{
	FILE* fp = fopen(filename.c_str(), "wb+");
	if (NULL == fp) {
		return -1;
	}
	fwrite(buffer, 1, len, fp);
	fclose(fp);

	return 0;
}

#endif
