#include "stdafx.h"
#include "Process.h"
using namespace std;

string Process::thatFilenameOut;
ofstream Process::thatFile;
vector<unsigned> Process::thatFiltered;
vector<unsigned> Process::thatErrors;


void Process::Init(string filename_out_)	 
{
	thatFilenameOut = filename_out_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void Process::Filter(RevPolNotation& rpn_, vector<Army>& data_)
{
	unsigned i = 0;
	AnyWithType result;
	for (auto& e : data_)
	{
		try
		{
			result = rpn_.Evulate(boost::bind(&Army::Get, data_[i], _1));
			if (boost::any_cast<bool>(result.Data())) thatFiltered.push_back(i);
		}
		catch (Except& e)
		{
			thatErrors.push_back(i);
		}
		if (i % 100 == 0) cout << "Filtered frames: " << i << "\r";
		++i;
	}
	cout << "Frames filtering finished. Filtered " << thatFiltered.size() << ". Errors: " << thatErrors.size() << "\n";
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void Process::PrintFiltered(vector<Army>& data_, string filename_in_, string filter_)
{
	
	/*Open file to write result and write title*/
	thatFile.open(thatFilenameOut, ofstream::out);
	string title = "Filename with data: " + filename_in_ +
		"\nTotal frames in file: " + to_string(data_.size() + 1) +
		"\nFilter expression: " + filter_ +
		"\nTime spent: " + Time::Get() + "\n\n";
	thatFile.write(title.c_str(), title.length());

	/*Write filtered frames*/
	unsigned i = 0;
	for (auto& e : thatFiltered)
	{
		thatFile.write(data_[e].GetRaw().c_str(),data_[e].GetRaw().length());
		thatFile.flush();
		if (i % 100 == 0) cout << "Written frames: " << i << "\r";
		++i;
	}
	thatFile.close();
	cout << "Frames writing finished. Writed " << i << "\n";

	/*write errors*/
	i = 0;
	thatFile.open(thatFilenameOut + "errors", ofstream::out);
	for (auto& e : thatErrors)
	{
		thatFile.write(data_[e].GetRaw().c_str(), data_[e].GetRaw().length());
		thatFile.flush();
		if (i % 100 == 0) cout << "Written error frames: " << i << "\r";
		++i;
	}
	thatFile.close();
	cout << "Frames writing errors finished. Writed " << i << "\n";

}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------