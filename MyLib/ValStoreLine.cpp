#include "stdafx.h"
#include "ValStoreLine.h"

using namespace std;
typedef ValStoreLine VSL;

string  VSL::ToString()
{
	string result;
	for ( auto&e : thatDataVals )
		result += e.first + "=" + e.second + "\n";
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSL::SetSubNames(string name_)
{
	if ( find(thatDataNames.begin(), thatDataNames.end(), name_) != thatDataNames.end() ) return;
	
	auto v = STR::StrToVec(name_, ".");
	string name_tmp = name_;
	for ( unsigned i = v.size()-1; i <v.size(); --i )
	{
		if ( find(thatDataNames.begin(), thatDataNames.end(), name_tmp) != thatDataNames.end() ) return;

		thatDataNames.push_back(name_tmp);
		thatDataVals.insert({ name_tmp, "" });
		name_tmp = STR::SubStrFromTo(name_tmp, 0, name_tmp.length() - (v[i].length()+1));
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string VSL::Val(string name_)
{
	if ( name_.empty() ) return "";
	auto it = thatDataVals.find(name_);
	if ( it == thatDataVals.end() ) return "";
	else return it->second;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSL::SetVal(string name_, string val_)
{
	if ( name_.empty() ) return;
	SetSubNames(name_);
	thatDataVals[name_] = val_;
	sort(thatDataNames.begin(), thatDataNames.end());
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSL::DelVal(string name_)
{
	if ( name_.empty() ) return;
	thatDataVals.erase(name_);
	thatDataNames.erase(remove(thatDataNames.begin(), thatDataNames.end(), name_), thatDataNames.end());
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
VSL VSL::ValSubTree(string name_)
{
	VSL result;
	if ( name_.empty() )
	{
		result.thatDataNames = thatDataNames;
		result.thatDataVals = thatDataVals;
		return result;
	}
	bool root = true;
	string name_root = STR::SubStrFromTo(name_, name_.find_last_of(".") + 1, string::npos);
	string name_cut;
	auto it = find(thatDataNames.begin(), thatDataNames.end(), name_);
	while ( 1 )
	{
		if ( it == thatDataNames.end() ) break; // if not found
		if ( STR::SubStrFromTo(*it, 0, name_.length()) != name_ ) break; // if name doesnt begin with name_
		

		name_cut = name_root + STR::SubStrFromTo(*it, name_.length() + 1, string::npos);
		result.thatDataVals[name_cut] = thatDataVals[*it];
		result.thatDataNames.push_back(name_cut);
		if ( root )
		{
			root = false;
			name_root += ".";
		}
		++it;
	}
	sort(result.thatDataNames.begin(), result.thatDataNames.end());
	return result; 
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSL::SetValSubTree(string name_, VSL val_)
{
	SetSubNames(name_);
	name_ += ".";
	for ( auto& e : val_.thatDataVals )
	{
		thatDataVals[name_ + e.first] = e.second;
		thatDataNames.push_back(name_ + e.first);
	}
	sort(thatDataNames.begin(), thatDataNames.end());
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSL::DelValSubTree(string name_)
{
	if ( name_.empty() ) return;
	auto it = find(thatDataNames.begin(), thatDataNames.end(), name_);
	while ( it != thatDataNames.end() || (*it).find(name_) != string::npos )
	{
		thatDataVals.erase(*it);
		thatDataNames.erase(remove(thatDataNames.begin(), thatDataNames.end(), *it), thatDataNames.end());
		it;
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