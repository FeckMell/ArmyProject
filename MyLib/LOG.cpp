#include "stdafx.h"
#include "LOG.h"
using namespace std;
map<string, ofstream> LOG::_Files;
vector<string> LOG::_FileNames;
string LOG::_LastDate;
LOG::SHP_Work LOG::_Work;
LOG::SHP_IO LOG::_Io = nullptr;
LOG::SHP_thread LOG::_Thread = nullptr;

void LOG::Init(vector<string> filenames_, SHP_IO io_)
{
	_FileNames = filenames_;
	_LastDate = to_iso_extended_string(boost::gregorian::day_clock::universal_day());
	for ( auto& e : _FileNames )
	{
		_Files[e].open(CFG::Val("PathLog") + "/" + _LastDate + "_" + e + ".log", ofstream::app);
	}		 
	if ( io_ == nullptr )
	{
		_Io.reset(new IO());
		_Work.reset(new Work(*_Io.get()));
		_Thread.reset(new thread([]{ _Io->run(); }));
	}
	else
	{
		_Io = io_;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG::Log(int lvl_, std::string where_, std::string what_)
{
	_Io->post(boost::bind(LOG::Write, lvl_, where_, what_));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG::Write(int lvl_, string where_, string what_)
{
	if ( STR::IsNumeric(CFG::Val("LogLevel")) ) { if ( lvl_ <= stoi(CFG::Val("LogLevel")) ) return; }
	CheckDate();
	string time_stamp = "\n\n" + TimeMS() + " :       ";
	what_ = time_stamp + what_;

	_Files[where_].write(what_.c_str(), what_.length());
	_Files[where_].flush();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG::ReinitFiles()
{
	_LastDate = to_iso_extended_string(boost::gregorian::day_clock::universal_day());
	for ( auto& e : _FileNames )
	{
		_Files[e].close();
		_Files[e].open(CFG::Val("PathLog") + "/" + _LastDate + "_" + e + ".log", ofstream::app);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string LOG::TimeMS()
{
	return to_iso_extended_string(boost::posix_time::microsec_clock::local_time());
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG::CheckDate()
{
	if ( _LastDate != to_iso_extended_string(boost::gregorian::day_clock::universal_day()) )
		ReinitFiles();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
