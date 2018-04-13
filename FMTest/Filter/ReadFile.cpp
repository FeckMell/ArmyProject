#include "stdafx.h"
#include "ReadFile.h"

string ReadFile::thatFilterSTR;
vector<string> ReadFile::thatData;


void ReadFile::ReadFilter(string filepath_)
{
	ifstream file;
	file.open(filepath_);
	if (file.is_open())
	{
		string file_line;
		vector<string> results;

		while (getline(file, file_line))
		{
			if (file_line[0] == '*') continue;
			if (file_line.empty()) continue;
			
			thatFilterSTR = file_line;
			break;
		}
		file.close();
	}
	else { throw Except("Could not open file " + filepath_); }

	if (thatFilterSTR.empty())
	{
		throw Except("File empty: " + filepath_);
	}

	cout << "\nFilter: _" << ReadFile::GetFilter() << "_\n";
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string ReadFile::GetFilter()
{
	return thatFilterSTR;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ReadFile::ReadData(string filepath_)
{
	ifstream file;
	file.open(filepath_);
	if (file.is_open())
	{
		unsigned i = 1;
		string file_line;
		string message;

		while (getline(file, file_line))
		{
			if (file_line[0] == '*') continue;
			if (file_line.empty())
			{
				
				if (message.empty()) continue;
				if (message.back() == '\n') message.pop_back();
				if (message.back() == '\n') message.pop_back();
				
				thatData.push_back(message);
				++i;
				if (i % 100 == 0) cout << "Read: " << i << "frames\r";
				message.clear();
				continue;
			}

			message += file_line + "\n";
		}
		file.close();
	}
	else { throw Except("Could not open file " + filepath_); }

	if (thatData.empty())
	{
		throw Except("File empty: " + filepath_);
	}

	cout << "Reading frames finished! Frames readed: " << thatData.size() + 1 << "\n";
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string>* ReadFile::GetData()
{
	return &thatData;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ReadFile::FreeData()
{
	thatData.clear();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ReadFile::ParseData(vector<Army>& result_)
{
	unsigned i = 0;
	for (auto& e: thatData)
	{
		++i;
		result_.push_back(Army(e));
		if (i % 100 == 0) cout << "Converted " << i << " frames\r";
	}
	cout << "Parsing data finished! Frames converted: " << result_.size() + 1 << "\n";
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------