#pragma once

#ifdef WIN32
#include <SDKDDKVer.h>
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
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