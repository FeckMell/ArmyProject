#include "stdafx.h"
#include "ValStoreTree.h"

using namespace std;
typedef ValStoreTree VST;
typedef ValStoreTreeEntry VSTE;

string VST::PrintAll()
{
	unsigned lvl = 0;
	string result = "";
	for ( auto&e : thatData )
	{
		result += "\n" + e.first + "=" + e.second.PrintAll(lvl);
	}
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string VST::Val(string name_)
{
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");
	return thatData[name[lvl]].Val(name, lvl);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VST::SetVal(string name_, string val_)
{
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");
	thatData[name[lvl]].SetVal(name, lvl, val_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VST::DelVal(string name_)
{
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");
	thatData[name[lvl]].DelVal(name, lvl);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
VST VST::ValSubTree(string name_)
{
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");
	VSTE found = thatData[name[lvl]].ValSubTree(name, lvl);
	lvl = 0;
	string name_node = found.NodeName({ " " }, lvl);
	cout << "\nname=" << name_node;
	return VST();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VST::SetValSubTree(string name_, VST val_)
{
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");
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