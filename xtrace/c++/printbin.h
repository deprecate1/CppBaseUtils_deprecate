#ifndef __PRINT_BIN_2015_H
#define __PRINT_BIN_2015_H
#include "xtrace.h"

#define DEBUG_PRINT_BIN

#define PRINT_BYTE_PER_LINE		16
#ifdef DEBUG_PRINT_BIN
static inline void printbin(void *buffer, int len)
{
	XTRACE(RGB(255, 0, 0), _T("\n"));

	int i;
	for(i = 0; i < len; i++) {
		if(0 != i && 0 == i % PRINT_BYTE_PER_LINE)
			XTRACE(RGB(255, 0, 0), _T("\n"));

		XTRACE(RGB(255, 0, 0), _T("%02X "), ((unsigned char *)buffer)[i]);
	}
	XTRACE(RGB(255, 0, 0), _T("\n"));
}
#else
#define printbin(buffer, len)
#endif

#endif
