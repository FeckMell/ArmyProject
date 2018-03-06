#include "stdafx.h"
#include "CFG.h"

using namespace std;
ValStoreLine CFG::thatData;

string CFG::Val(string name_)
{
	return thatData.Val(name_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::SetVal(string name_, string value_)
{
	thatData.SetVal(name_, value_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::SetVal(map<string, string> data_)
{
	for ( auto& e : data_ ) thatData.SetVal(e.first, e.second); 
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string CFG::ToString()
{
	string result = "\nConfiguration params:\n";
	result += thatData.ToString();
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::Init(string path_)
{
	SetVal("PathExe", STR::ReplaceInStrAll(path_, "\\", "/"));
	ParsePath();
	Parse();
	if ( !Val("ExtraCFG").empty() ) ParseExtra();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::InitWithDefaults(string path_, std::map<string, string> defaults_)
{
	SetVal("PathExe", STR::ReplaceInStrAll(path_, "\\", "/"));
	ParsePath();
	for ( auto&e : defaults_ ) thatData.SetVal(e.first, e.second);
	Parse();
	if ( !Val("ExtraCFG").empty() ) ParseExtra();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::ParseExtra()
{
	ifstream file;
	file.open(Val("PathHome") + Val("ExtraCFG"));
	if ( file.is_open() )
	{
		string file_line;
		vector<string> results;

		while ( getline(file, file_line) && (file_line.substr(0, 3) != "***") )
		{
			results = STR::StrToVec(file_line, "=");
			if ( results.size() == 2 ) SetVal(results[0], results[1]);
		}
		file.close();
	}
	else { SetVal("Error", "Could not open ExtraCFG. Check it or delete it from fm.cfg.\nParsed params in fm.cfg:\n" + ToString()); }
	if ( !Val("Error").empty() )
	{
		cout << "\n" + Val("Error");
		system("pause");
		exit(-1);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::ParsePath()
{
	SetVal("PathExe", STR::SubStrFromTo(Val("PathExe"), 0, Val("PathExe").find_last_of("/") + 1));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::Parse()
{
	ifstream file;
	file.open(Val("PathExe") + "fm.cfg");
	if ( file.is_open() )
	{
		string file_line;
		vector<string> results;

		while ( getline(file, file_line) && (file_line.substr(0, 3) != "***") )
		{
			results = STR::StrToVec(file_line, "=");
			SetVal(results[0], results[1]);
		}
		file.close();
	}
	else { SetVal("Error", "Could not open fm.cfg file. Check its existanse or name. Name Must \"be fm.cfg\".\n"); }
	if ( !Val("Error").empty() )
	{
		cout << "\n" + Val("Error");
		system("pause");
		exit(-1);
	}
	if ( Val("PathHome").empty() ) SetVal("PathHome", Val("PathExe"));
	if ( Val("Logs.Path").empty() ) SetVal("Logs.Path", Val("PathHome"));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------