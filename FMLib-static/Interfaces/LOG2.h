#pragma once
#include "stdafx.h"
#include "Interfaces\CFG.h"
#include "CommonTypes\DataStorage\ValStoreLineT.h"

#undef LOG2_Class_Off
#define LOG2_Class_Off
#ifndef LOG2_Class_Off
class LOG2
{
private:

	//typedef std::shared_ptr<std::thread> SHP_thread;
	//typedef boost::asio::io_service IO;
	//typedef std::shared_ptr<boost::asio::io_service> SHP_IO;
	//typedef boost::asio::io_service::work Work;
	//typedef std::shared_ptr<boost::asio::io_service::work> SHP_Work;
	//typedef std::string string;

	LOG2() {}
	~LOG2() {}

	static void Write(int lvl_, std::string where_, std::string what_);

	static void SetConfig();
	static void ReinitFiles();
	static std::string TimeMS();
	static void CheckDate();

	/*Init*/
	static void OpenFiles(bool opened_ = true);
	/*Init END*/

	/*Format*/
	static void SetDefaults();
	static void SetFuncs();
	/*Format END*/

	static std::map<std::string, std::ofstream> thatFiles;
	static std::shared_ptr<boost::asio::io_service::work> thatWork;
	static std::shared_ptr<boost::asio::io_service> thatIo;
	static std::shared_ptr<std::thread> thatThread;
	static ValStoreLineT<std::string> thatData;
	static std::map<std::string, std::vector<boost::function<std::string()>>> thatFuncs;
	//static std::vector<string> thatFileNames;
	//static string thatLastDate;

public:
	
	enum Lvl { trace, debug, info, info2, error, fatal };

	static void Init(std::vector<std::string> filenames_, std::shared_ptr<boost::asio::io_service> io_ = nullptr);
	static void AddFile(std::string filename_);
	static void RemFile(std::string filename_);
	/**/
	static void Log(int lvl_, std::string where_, std::string what_);

};
#endif
