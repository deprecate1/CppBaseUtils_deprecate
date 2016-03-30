from [https://github.com/SergiusTheBest/plog](https://github.com/SergiusTheBest/plog "https://github.com/SergiusTheBest/plog")


全部是头文件，封装
=================================

    #include "plog/Log.h"

	#define LOG_BIN(buf, size) 							\
		do {									\
			int i;								\
			char buf[128] = "";						\
			char temp[32] = "";						\
			for (i = 0; i < size - 1; i++){ 				\
				if (0 == i % 16){					\
					if (0 != i) {					\
						LOG_ONLY("%s", buf);			\
						strcpy(buf, "");			\
					}						\
					sprintf(temp, "0x%04x: ", i);			\
					strcat(buf, temp);				\
				}							\
				sprintf(temp, "%02x ", ((char*)buf)[i]);		\
				strcat(buf, temp);					\
			}								\
			sprintf(temp, "%02x", ((char*)buf)[i]);			\
			strcat(buf, temp);						\
			LOG_ONLY("%s", buf);						\
		} while(0)
	
	#define LOG_PRINT(...) 	do {							\
						char buf123[256] = "";			\
						sprintf(buf123,__VA_ARGS__);		\
						printf("%s\n", buf123);			\
						fflush(stdout);				\
						LOG_WARNING << buf123;			\
					} while (0)
	
	
	
	#define LOG_LINE() 		do {						\
						LOG_WARNING << __LINE__;		\
					} while (0)
	
	
	#define LOG_PLINE() 		do {						\
						printf("%s(%d)\n", __func__, __LINE__);	\
						fflush(stdout);				\
						LOG_WARNING << __LINE__;		\
					} while (0)
	
	
	#define LOG_ONLY(arg...) 	do {						\
						char buf123[256] = "";			\
						sprintf(buf123, ##arg);			\
						LOG_WARNING << buf123;			\
					} while (0)




	LOG_PRINT("compile at: %s, %s, sysclk: %d", __DATE__, __TIME__, (int)sysconf(_SC_CLK_TCK));
	LOG_PRINT("start data server......");

直接使用
======================
	LOG_WARNING << "hello, world.\n";
