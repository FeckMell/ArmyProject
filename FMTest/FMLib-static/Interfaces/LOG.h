#pragma once
#ifdef WIN32
#include <SDKDDKVer.h>
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN          
#endif
//#include "stdafx.h"
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>
#include <boost\asio.hpp>
#include <boost\bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Interfaces\CFG.h"

class LOG
{
public:

	enum Lvl { trace, debug, info, info2, error, fatal };

	static void Init(std::vector<std::string> filenames_, std::shared_ptr<boost::asio::io_service> io_ = nullptr);
	static void Log(int lvl_, std::string where_, std::string what_);

private:

	LOG() {}
	~LOG() {}

	static void Write(int lvl_, std::string where_, std::string what_);

	static void ReinitFiles();
	static std::string TimeMS();
	static void CheckDate();

	static std::map<std::string, std::ofstream> thatFiles;
	static std::vector<std::string> thatFileNames;
	static std::string thatLastDate;
	static std::shared_ptr<boost::asio::io_service::work> thatWork;
	static std::shared_ptr<boost::asio::io_service> thatIo;
	static std::shared_ptr<std::thread> thatThread;

};

