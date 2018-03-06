#pragma once

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <SDKDDKVer.h>
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
