#pragma once
#include "stdafx.h"
#include "CFG.h"

class LOG
{
public:
	typedef std::shared_ptr<std::thread> SHP_thread;
	typedef boost::asio::io_service IO;
	typedef std::shared_ptr<IO> SHP_IO;
	typedef boost::asio::io_service::work Work;
	typedef std::shared_ptr<Work> SHP_Work;
	enum Lvl { trace, debug, info, info2, error, fatal };

	static void Init(std::vector<std::string> filenames_, SHP_IO io_ = nullptr);
	static void Log(int lvl_, std::string where_, std::string what_);

private:

	LOG() {}
	~LOG() {}

	static void Write(int lvl_, std::string where_, std::string what_);

	static void ReinitFiles();
	static std::string TimeMS();
	static void CheckDate();

	static std::map<std::string, std::ofstream> _Files;
	static std::vector<std::string> _FileNames;
	static std::string _LastDate;
	static SHP_Work _Work;
	static SHP_IO _Io;
	static SHP_thread _Thread;

};

