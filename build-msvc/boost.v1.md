下载
========
http://www.boost.org/     下载boost_1_70_0.7z(不建议用1_61_0或以下版本，里面依赖python sdk很麻烦)

visual studio 动态库
========
开始菜单找到‘VS2013 X86 本机工具命令提示符’，执行bootstrap.bat，
正常的话提示执行b2：

b2.exe   toolset=msvc-14.2						强制使用vs2019

b2.exe   toolset=msvc-14.1						强制使用vs2017

b2.exe   toolset=msvc-14.0						强制使用vs2015

b2.exe   toolset=msvc-12.0						强制使用vs2013

后面之所以加toolset参数，是因为：即便打开vs2017的prompt，因为安装了vs2019，由于路径的原因会用vs2019的编译器，这里起强制作用


visual studio 静态库
========

boost会检测当前visual studio工程static或者multi thread等配置，然而上面的动态库并不会生成类似*sgd**.lib这样的库，也就是说dynamic和static必须各编译一套（相应的需要准备两个文件：boost.props和boost_static.props）

b2.exe   toolset=msvc-14.2    link=static   runtime-link=static						强制使用vs2019

b2.exe   toolset=msvc-14.1    link=static   runtime-link=static						强制使用vs2017

b2.exe   toolset=msvc-14.0    link=static   runtime-link=static						强制使用vs2015

b2.exe   toolset=msvc-12.0    link=static   runtime-link=static						强制使用vs2013



b2执行成功会有如下提示：
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


