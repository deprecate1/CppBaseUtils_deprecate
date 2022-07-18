#ifndef __PRINTBIN_2022_0614_H__
#define __PRINTBIN_2022_0614_H__
// test
/*
char buf[256];
for (int i = 0; i < 256; i++)
	buf[i] = i;

printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 3, 31).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 3, 32).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 3, 33).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 158, 31).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 158, 32).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 158, 33).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 158, 161).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 161, 31).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 161, 32).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 161, 33).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 161, 161).c_str());
printf("%04d: \n%s\n", __LINE__, printbin2string(buf, 162, 161).c_str());
*/

#include <string>
#include <stdio.h>
#include <ctype.h>

static std::string __printline(void* buffer, int len, int linesize)
{
	std::string out;
	for (int i = 0; i < linesize; i++) {
		char buf[8] = "";
		if (i < len) {
			sprintf_s(buf, "%02x ", ((unsigned char*)buffer)[i]);
		} else {
			strcpy_s(buf, "** ");
			//strcpy_s(buf, "   ");
		}
		out += buf;
	}
	out += "| ";
	for (int i = 0; i < len; i++) {
		char ch = ((char*)buffer)[i];
		char buf[8] = "";
		if (ch > 0 && isprint(ch))
			sprintf_s(buf, "%c", ch);
		else
			strcpy_s(buf, ".");
		out += buf;
	}
	return out;
}

#define __DEFAULT_BYTES_PRINT_PER_LINE		32
static std::string printbin2string(void* buffer, int len, int linesize = __DEFAULT_BYTES_PRINT_PER_LINE)
{
	std::string out;
	for (int i = 0; i < len; i += linesize) {
		int leave = len - i;
		if (leave >= linesize) {
			out += __printline((char*)buffer + i, linesize, linesize);
		} else {
			out += __printline((char*)buffer + i, leave, linesize);
		}

		if (i + linesize < len)
			out += "\n";
	}
	return out;
}

#endif

