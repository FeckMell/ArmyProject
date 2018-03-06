#include "stdafx.h"
#include "ValStoreTree.h"
using namespace std;

string ValStoreTree::ValStoreTreeEntry::PrintAll(unsigned lvl_)
{
	lvl_++;
	string space = STR::GenMultTimes(" ", lvl_/* * 2*/);
	string result = thatData;
	for ( auto&e : thatDataTree )
	{
		result += "\n" + space + e.first + "=" + e.second.PrintAll(lvl_);
	}
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
ValStoreTree::ValStoreTreeEntry::ValStoreTreeEntry(string name_) : thatName(name_)
{
	;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ValStoreTree::ValStoreTreeEntry::SetVal(vector<string> name_, unsigned& lvl_, string val_)
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
			thatDataTree.insert({ name_[lvl_], ValStoreTree::ValStoreTreeEntry(name_[lvl_]) });
			thatDataTree[name_[lvl_]].SetVal(name_, lvl_, val_);
		}
		else it->second.SetVal(name_, lvl_, val_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string ValStoreTree::ValStoreTreeEntry::Val(vector<string> name_, unsigned& lvl_)
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
void ValStoreTree::ValStoreTreeEntry::DelVal(vector<string> name_, unsigned& lvl_)
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
ValStoreTree::ValStoreTreeEntry ValStoreTree::ValStoreTreeEntry::ValSubTree(vector<string> name_, unsigned& lvl_)
{
	if ( lvl_ == name_.size() - 1 ) return *this;
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if (it == thatDataTree.end())	return ValStoreTreeEntry();
		else return it->second.ValSubTree(name_, lvl_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ValStoreTree::ValStoreTreeEntry::SetValSubTree(vector<string> name_, unsigned& lvl_, ValStoreTreeEntry val_)
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
			thatDataTree.insert({ name_[lvl_], ValStoreTreeEntry(name_[lvl_]) });
			thatDataTree[name_[lvl_]].SetValSubTree(name_, lvl_, val_);
		}
		else it->second.SetValSubTree(name_, lvl_, val_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void ValStoreTree::ValStoreTreeEntry::DelValSubTree(vector<string> name_, unsigned& lvl_)
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
map<string, ValStoreTree::ValStoreTreeEntry> ValStoreTree::ValStoreTreeEntry::ChildNodes(vector<string> name_, unsigned& lvl_)
{
	if ( lvl_ == name_.size() - 1 ) return thatDataTree;
	else
	{
		lvl_++;
		auto it = thatDataTree.find(name_[lvl_]);
		if (it == thatDataTree.end())	return map<string, ValStoreTreeEntry>();
		else return it->second.ChildNodes(name_, lvl_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> ValStoreTree::ValStoreTreeEntry::ChildNodesNames(vector<string> name_, unsigned& lvl_)
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
string ValStoreTree::ValStoreTreeEntry::ToString(string path_)
{
	string result = "";

	if ( !thatData.empty() ) result += path_ + "=" + thatData;

	path_ += ".";
	for ( auto& e : thatDataTree ) result += e.second.ToString(path_ + e.first);
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

