#include "stdafx.h"
#include "CFG.h"
using namespace std;
map<string, string> CFG::thatDataMap;

std::string CFG::Val(std::string name_)
{
	return thatDataMap[name_];
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::SetVal(std::string name_, std::string value_)
{
	thatDataMap[name_] = value_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::SetVal(std::map<std::string, std::string> data_)
{
	for (auto& e : data_) thatDataMap[e.first] = e.second;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
std::string CFG::ToStringAll()
{
	string result = "\nConfiguration params:\n";
	for (auto& e : thatDataMap) result += "\n" + e.first + "=_" + e.second + "_";
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::Init(std::string path_)
{
	SetVal("PathExe", STR::ReplaceInStrAll(path_, "\\", "/"));
	ParsePath();
	Parse();
	if ( Val("ExtraCFG") != "" ) ParseExtra();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void CFG::ParseExtra()
{
	ifstream file;
	file.open(Val("PathHome") + Val("ExtraCFG"));
	if (file.is_open())
	{
		string file_line;
		cmatch results;
		regex reg3(R"((\w+)=(\S+))");

		while (getline(file, file_line) && (file_line.substr(0, 3) != "***"))
		{
			regex_match(file_line.c_str(), results, reg3);
			SetVal(results.str(1), results.str(2));
		}
		file.close();
	}
	else { SetVal("Error", "Could not open ExtraCFG. Check it or delete it from fm.cfg.\nParsed params in fm.cfg:\n" + ToStringAll()); }
	if ( Val("Error") != "" )
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
	if (file.is_open())
	{
		string file_line;
		cmatch results;
		regex reg(R"((\w+)=(\S+))");

		while (getline(file, file_line) && (file_line.substr(0, 3) != "***"))
		{
			regex_match(file_line.c_str(), results, reg);
			SetVal(results.str(1), results.str(2));
		}
		file.close();
	}
	else { SetVal("Error", "Could not open fm.cfg file. Check its existanse or name. Name Must \"be fm.cfg\".\n"); }
	if ( Val("Error") != "" )
	{
		cout << "\n" + Val("Error");
		system("pause");
		exit(-1);
	}
	if ( Val("PathHome") == "" ) SetVal("PathHome", Val("PathExe"));
	if ( Val("PathLog") == "" ) SetVal("PathLog", Val("PathHome"));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------