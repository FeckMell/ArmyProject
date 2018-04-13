//#include "stdafx.h"
#include "LOG.h"
using namespace std;
map<string, ofstream> LOG::thatFiles;
vector<string> LOG::thatFileNames;
string LOG::thatLastDate;
std::shared_ptr<boost::asio::io_service::work> LOG::thatWork;
std::shared_ptr<boost::asio::io_service> LOG::thatIo = nullptr;
std::shared_ptr<std::thread> LOG::thatThread = nullptr;

void LOG::Init(vector<string> filenames_, std::shared_ptr<boost::asio::io_service> io_)
{
	thatFileNames = filenames_;
	thatLastDate = to_iso_extended_string(boost::gregorian::day_clock::universal_day());
	for ( auto& e : thatFileNames )
	{
		thatFiles[e].open(CFG::Val("Logs.Path") + "/" + thatLastDate + "_" + e + ".log", ofstream::app);
	}		 
	if ( io_ == nullptr )
	{
		thatIo.reset(new boost::asio::io_service());
		thatWork.reset(new boost::asio::io_service::work(*thatIo.get()));
		thatThread.reset(new thread([]{ thatIo->run(); }));
	}
	else
	{
		thatIo = io_;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG::Log(int lvl_, std::string where_, std::string what_)
{
	thatIo->post(boost::bind(LOG::Write, lvl_, where_, what_));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG::Write(int lvl_, string where_, string what_)
{
	if ( STR::IsNumeric(CFG::Val("Logs.Record.Level.Current")) ) { if ( lvl_ <= stoi(CFG::Val("Logs.Record.Level.Current")) ) return; }
	CheckDate();
	string time_stamp = "\n\n" + TimeMS() + " :       ";
	what_ = time_stamp + what_;

	thatFiles[where_].write(what_.c_str(), what_.length());
	thatFiles[where_].flush();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void LOG::ReinitFiles()
{
	thatLastDate = to_iso_extended_string(boost::gregorian::day_clock::universal_day());
	for ( auto& e : thatFileNames )
	{
		thatFiles[e].close();
		thatFiles[e].open(CFG::Val("Logs.Path") + "/" + thatLastDate + "_" + e + ".log", ofstream::app);
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
	if ( thatLastDate != to_iso_extended_string(boost::gregorian::day_clock::universal_day()) )
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
