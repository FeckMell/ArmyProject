#pragma once
#include "stdafx.h"
#include "CFG.h"
#include "ValStoreTree.h"

class LOG2
{
private:

	typedef std::shared_ptr<std::thread> SHP_thread;
	typedef boost::asio::io_service IO;
	typedef std::shared_ptr<IO> SHP_IO;
	typedef boost::asio::io_service::work Work;
	typedef std::shared_ptr<Work> SHP_Work;
	typedef std::string string;

	LOG2() {}
	~LOG2() {}

	static void Write(int lvl_, string where_, string what_);

	static void SetConfig();
	static void ReinitFiles();
	static string TimeMS();
	static void CheckDate();

	/*Init*/
	static void OpenFiles(bool opened_ = true);
	/*Init END*/

	/*Format*/
	static void SetDefaults();
	static void SetFuncs();
	/*Format END*/

	static std::map<string, std::ofstream> thatFiles;
	static SHP_Work thatWork;
	static SHP_IO thatIo;
	static SHP_thread thatThread;
	static ValStoreTree thatData;
	static std::map<string,vector<boost::function<string()>>> thatFuncs;
	//static std::vector<string> thatFileNames;
	//static string thatLastDate;

public:
	
	enum Lvl { trace, debug, info, info2, error, fatal };

	static void Init(std::vector<string> filenames_, SHP_IO io_ = nullptr);
	static void AddFile(string filename_);
	static void RemFile(string filename_);
	/**/
	static void Log(int lvl_, string where_, string what_);

};
