#include "stdafx.h"
#include "ValStoreTreeEntry.h"
using namespace std;
typedef ValStoreTreeEntry VSTE;

string VSTE::PrintAll(unsigned lvl_)
{
	lvl_++;
	string space = STR::GenMultTimes(" ", lvl_/* * 2*/);
	string result = thatData;
	for ( auto&e : thatDataTree )
	{
		result += "\n" + space + e.first + "_=" + e.second.PrintAll(lvl_);
	}
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
VSTE::ValStoreTreeEntry(string name_) : thatName(name_)
{
	;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSTE::SetVal(vector<string> name_, unsigned& lvl_, string val_)
{
	if ( lvl_ == name_.size() - 1 )
	{
		thatData = val_;
		thatName = name_[lvl_];
	}
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if ( it == thatDataTree.end() )
		{
			thatDataTree.insert({ name_[lvl_], VSTE(name_[lvl_]) });
			thatDataTree[name_[lvl_]].SetVal(name_, lvl_, val_);
		}
		else it->second.SetVal(name_, lvl_, val_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string VSTE::Val(vector<string> name_, unsigned& lvl_)
{
	if ( lvl_ == name_.size() - 1 )	return thatData;
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if ( it == thatDataTree.end() )	return "";
		else return it->second.Val(name_, lvl_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSTE::DelVal(vector<string> name_, unsigned& lvl_)
{
	if ( lvl_ == name_.size() - 1 ) thatData = "";
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if ( it == thatDataTree.end() )	return;
		else it->second.DelVal(name_, lvl_);		
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
VSTE VSTE::ValSubTree(vector<string> name_, unsigned& lvl_)
{
	if ( lvl_ == name_.size() - 1 ) return *this;
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if ( it == thatDataTree.end() )	return VSTE();
		else return it->second.ValSubTree(name_, lvl_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSTE::SetValSubTree(vector<string> name_, unsigned& lvl_, VSTE val_)
{
	if ( lvl_ + 1 == name_.size() )
	{
		thatDataTree[val_.NodeName()] = val_; //TODO - exclude .NodeName()
		return;
	}
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if ( it == thatDataTree.end() )
		{
			thatDataTree.insert({ name_[lvl_], VSTE(name_[lvl_]) });
			thatDataTree[name_[lvl_]].SetValSubTree(name_, lvl_, val_);
		}
		else it->second.SetValSubTree(name_, lvl_, val_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void VSTE::DelValSubTree(vector<string> name_, unsigned& lvl_)
{
	/* обработка случая на уровень выше name_.size() == 1*/
	if ( lvl_ + 2 == name_.size() ) thatDataTree.erase(thatDataTree.find(name_.back()));
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if ( it == thatDataTree.end() )	return;
		else it->second.DelValSubTree(name_, lvl_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
map<string, VSTE> VSTE::ChildNodes(vector<string> name_, unsigned& lvl_)
{
	if ( lvl_ == name_.size() - 1 ) return thatDataTree;
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if ( it == thatDataTree.end() )	return map<string, VSTE>();
		else return it->second.ChildNodes(name_, lvl_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> VSTE::ChildNodesNames(vector<string> name_, unsigned& lvl_)
{
	if ( lvl_ == name_.size() - 1 )
	{
		vector<string> result;
		for ( auto& e : thatDataTree ) result.push_back(e.first);
		return result;
	}
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if ( it == thatDataTree.end() )	return vector<string>();
		else return it->second.ChildNodesNames(name_, lvl_);
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

