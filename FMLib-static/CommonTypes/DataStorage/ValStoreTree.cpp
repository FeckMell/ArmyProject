#include "stdafx.h"
#include "ValStoreTree.h"

using namespace std;

string ValStoreTree::PrintAll()
{
	unsigned lvl_ = 0;
	string result = "";
	for ( auto& e : thatDataTree ) result +=e.first + "=" + e.second.PrintAll(lvl_) + "\n";
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string ValStoreTree::Val(string name_)
{
	if ( name_.empty() ) return "";
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");

	auto it = thatDataTree.find(name[lvl]);
	if ( it == thatDataTree.end() )	return "";
	else return it->second.Val(name, lvl);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ValStoreTree::SetVal(string name_, string val_)
{
	if ( name_.empty() ) return;
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");

	auto it = thatDataTree.find(name[lvl]);
	if ( it == thatDataTree.end() )
	{
		thatDataTree.insert({ name[lvl], ValStoreTreeEntry(name[lvl]) });
		thatDataTree[name[lvl]].SetVal(name, lvl, val_);
	}
	else it->second.SetVal(name, lvl, val_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ValStoreTree::DelVal(string name_)
{
	if ( name_.empty() ) return;
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");

	auto it = thatDataTree.find(name[lvl]);
	if ( it == thatDataTree.end() )	return ;
	else it->second.DelVal(name, lvl);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
ValStoreTree ValStoreTree::ValSubTree(string name_)
{
	if (name_.empty()) return ValStoreTree();
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");

	auto it = thatDataTree.find(name[lvl]);
	if (it == thatDataTree.end())	return ValStoreTree();
	else
	{
		ValStoreTreeEntry preresult = it->second.ValSubTree(name, lvl);
		if (preresult.NodeName().empty()) return ValStoreTree();
		else
		{
			ValStoreTree result;
			result.thatDataTree[preresult.NodeName()] = preresult;
			return result;
		}
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
/* Not optimal in:*/
void ValStoreTree::SetValSubTree(string name_, ValStoreTree val_)
{
	if ( name_.empty() )
	{
		thatDataTree = val_.thatDataTree;
		return;
	}
	else
	{
		unsigned lvl = 0;
		vector<string> name = STR::StrToVec(name_, ".");

		auto it = thatDataTree.find(name[lvl]);
		if ( it == thatDataTree.end() )
		{
			thatDataTree.insert({ name[lvl], ValStoreTreeEntry(name[lvl]) });
			for ( auto& e : val_.thatDataTree ) //HERE
			{
				thatDataTree[name[lvl]].SetValSubTree(name, lvl, e.second);
			}
		}
		else
		{
			for ( auto& e : val_.thatDataTree )//AND HERE
			{
				it->second.SetValSubTree(name, lvl, e.second);
			}
		}
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ValStoreTree::DelValSubTree(string name_)
{
	if ( name_.empty() )
	{
		thatDataTree = map<string, ValStoreTreeEntry>();
		return;
	}
	unsigned lvl = 0;
	vector<string> name = STR::StrToVec(name_, ".");

	auto it = thatDataTree.find(name[lvl]);
	if ( it == thatDataTree.end() ) return;
	else
	{
		if ( name.size() == 1 ) thatDataTree.erase(it);
		else it->second.DelValSubTree(name, lvl);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string ValStoreTree::ToString()
{
	string result = "";
	for ( auto& e : thatDataTree ) result += e.second.ToString("\n" + e.first);
	return result;
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