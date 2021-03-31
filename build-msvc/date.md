地址：https://github.com/HowardHinnant/date



集成：

include&src 下的文件（有个.mm后缀的不需要）



其它：

查阅代码，里面有个函数remote_download()，主要下载2个文件：

https://raw.githubusercontent.com/unicode-org/cldr/master/common/supplemental/windowsZones.xml

https://www.iana.org/time-zones   下载里面的tzdata2021a.tar.gz

把下载的文件解压到.\dir123\tzdata\ 里面（解压后：文件夹里面会有asia，windowsZones.xml等文件）



接口：

	date::set_install(".\dir123\tzdata\ ");
	std::string result_tz = date::current_zone()->name();


