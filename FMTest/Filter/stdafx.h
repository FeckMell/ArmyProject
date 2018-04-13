// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once
#ifdef WIN32
#include <SDKDDKVer.h>
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN             // »сключите редко используемые компоненты из заголовков Windows
#endif
/* <\> C++ */
#include <stdio.h>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <queue>
#include <stack>

#include <iostream>
#include <fstream>

#include <chrono>
#include <thread>
#include <regex>
#include <mutex>
/* </> C++ */

/* <\> BOOST */
#include <boost\asio.hpp>
#include <boost\function.hpp>
#include <boost\bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/exception/to_string.hpp>
#include <boost/any.hpp>
/* </> BOOST */

#pragma comment(lib,"FMLib-static.lib")



// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
