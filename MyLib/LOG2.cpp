#include "stdafx.h"
#include "LOG2.h"

using namespace std;

map<string, ofstream> LOG2::thatFiles;
LOG2::SHP_Work LOG2::thatWork;
LOG2::SHP_IO LOG2::thatIo;
LOG2::SHP_thread LOG2::thatThread;
ValStoreLine LOG2::thatData;
map<string, vector<boost::function<string()>>> LOG2::thatFuncs;

void LOG2::Init(vector<string> filenames_, SHP_IO io_)
{
	SetConfig();
	for ( auto& e : filenames_ ) thatFiles.insert({ e, ofstream() });
	OpenFiles(false);
	
	if ( io_ == nullptr )
	{
		thatIo.reset(new IO());
		thatWork.reset(new Work(*thatIo.get()));
		thatThread.reset(new thread([]{ thatIo->run(); }));
	}
	else
	{
		thatIo = io_;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG2::SetConfig()
{
	SetDefaults();
	SetFuncs();
	//создать vector функций формата и тд
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG2::SetDefaults()
{
	map<string, string> def = {
		/*задать параметры логера*/
		{ "Logs.Record.Time", "true" },
		{ "Logs.Record.Time.Format", "Year-Month-Day-Hour-Minute-Second-Millisecond" },
		{ "Logs.Record.ThreadID", "true" },
		{ "Logs.Record.DeviderEnd", "true" },
		{ "Logs.Record.DeviderBegin", "true" },
		{ "Logs.Record.Devider.Format", "//*///------------------------------------------------------------------------------------------" },
		{ "Logs.Record.SpaceLinesNum", "1" },
		{ "Logs.Record.Level.Max", "6" },
		{ "Logs.Record.Level.Current", "3" },
		{ "Logs.File.Name.Format.Extension", "log" },
		{ "Logs.File.Name.Format.Date", "true" },
		{ "Logs.File.Name.Format.Date.Format", "Year-Month-Day" },
		{ "Logs.File.Name.Prefix", ""},
		{ "Logs.FileName.Suffix", "" },
		{ "Logs.File.OpenMode", "append" }
	};
	for ( auto&e : def )
		thatData.SetVal(e.first, e.second);
	thatData.SetVal("Logs.Path", CFG::Val("Logs.Path"));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG2::SetFuncs()
{
	/*Static*/
	if ( thatData.Val("Logs.Record.DeviderEnd") == "true" ) thatData.SetVal(thatData.Val("StaticRecordEnd") + thatData.Val("Logs.Record.Devider.Format"), "StaticRecordEnd");
	if ( thatData.Val("Logs.Record.DeviderBegin") == "true" ) thatData.SetVal(thatData.Val("StaticRecordBegin") + thatData.Val("Logs.Record.Devider.Format"), "StaticRecordBegin");
	if ( STR::IsNumeric(thatData.Val("Logs.Record.SpaceLinesNum")) ) thatData.SetVal(thatData.Val("StaticRecordEnd") + STR::GenMultTimes("\n", stoi(thatData.Val("Logs.Record.SpaceLinesNum"))), "StaticRecordEnd");
	else thatData.SetVal(thatData.Val("StaticRecordEnd") + STR::GenMultTimes("\n", 1), "StaticRecordEnd");
	/*Static End*/

	/*Funcs*/

	if ( thatData.Val("Logs.Record.Time") == "true" ) thatFuncs["RecordB"].push_back([&]{return to_iso_extended_string(boost::posix_time::microsec_clock::local_time()); });
	if ( thatData.Val("Logs.Record.ThreadID") == "true" ) thatFuncs["RecordB"].push_back([&]{ return boost::to_string(std::this_thread::get_id()); });
	/*Funcs End*/
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG2::OpenFiles(bool opened_)
{
	thatData.SetVal("LastDate", to_iso_extended_string(boost::gregorian::day_clock::universal_day()));
	string s = "";
	for ( auto& e : thatFiles )
	{
		if ( e.second.is_open() ) e.second.close();
	}
}

//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
