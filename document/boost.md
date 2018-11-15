下载
========
http://www.boost.org/     下载boost_1_68_0.7z(不建议用1_61_0，里面依赖python sdk很麻烦)

visual studio 2013编译
========
开始菜单找到‘VS2013 X86 本机工具命令提示符’，执行bootstrap.bat，
正常的话提示执行b2。b2执行成功会有如下提示：
![](https://github.com/wjx0912/CppBaseUtils/blob/master/document/image/boost.png)

使用
========
    
	#include "stdafx.h"
	#include <boost/regex.hpp>
	#include <iostream>
	#include <string>
	
	int main()
	{
		std::string line;
		boost::regex pattern("[a-zA-Z_][a-zA-Z0-9_]*");
		boost::smatch matches;
		//按“^Z 回车”退出
		std::cin >> line;
		while (std::cin) {
			if (boost::regex_match(line, matches, pattern))
				std::cout << "有效的标识符" << "" << std::endl;
			else
				std::cout << "无效标识符" << std::endl;
			std::cin >> line;
		}
		return 0;
	}

编译的时候把include和lib路径加入到工程
