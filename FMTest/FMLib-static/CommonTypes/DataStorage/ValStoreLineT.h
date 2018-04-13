#pragma once
//#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
#include "CommonTypes\DataStorage\AnyWithType.h"
#include "CommonTypes\Except.h"
#include "Interfaces\Str.h"

/*
Except:
"Empty node name"
"Node not found"
"Not string type"
*/

//#define ValStoreLine_Except_On

template<class _T> class ValStoreLineT
{
private:

	/*Data storage*/
	std::map<std::string, _T> thatDataVals;

	/*Check if @name_ is empty*/
	bool CheckEmpty(std::string name_);
	/*Check if element with @name_ exists*/
	AnyWithType CheckExist(std::string name_);

	/*Set all sub names for @name_ with default values*/
	void SetSubNames(std::string name_);

public:

	/*Return @thatDataVals converted to string*/
	std::string ToString();
	ValStoreLineT() {}

	/*Return all node names begins with @name_*/
	std::vector<std::string> NodesNamesAll(std::string name_ = "");
	/*Return all nodes names begins with @name_ and that doesnt have any childs*/
	std::vector<std::string> NodesNamesChild(std::string name_ = "");
	/*Check if node with name @name_ doestnt have childs*/
	bool IsFinal(std::string name_);

	/*Return stored element*/
	_T Val(std::string name_);
	/*Return sub tree begins with @name_*/
	ValStoreLineT<_T> ValSubTree(std::string name_);

	/*methods to set vals*/
	void SetVal(std::string name_, _T val_);
	void SetValSubTree(std::string name_, ValStoreLineT<_T> val_);
	void SetValSubTree(std::string name_, std::map<std::string, _T> val_);

	/*Methods to delete vals*/
	void DelVal(std::string name_);
	void DelValSubTree(std::string name_);

	/*Clear data*/
	void Clear();

};

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
template<class _T> bool ValStoreLineT<_T>::CheckEmpty(std::string name_)
{
	if (name_.empty())
	{
#ifdef ValStoreLine_Except_On
		throw Except("Empty node name");
#else
		return true;
#endif
	}
	else return false;
}
//*///------------------------------------------------------------------------------------------
template<class _T> AnyWithType ValStoreLineT<_T>::CheckExist(std::string name_)
{
	std::map<std::string, _T>::iterator it = thatDataVals.find(name_);
	if (it == thatDataVals.end())
	{
#ifdef ValStoreLine_Except_On
		throw Except("Node not found");
#endif
	}
	return AnyWithType(it, AnyWithType::OTHER);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> std::string ValStoreLineT<_T>::ToString()
{
	std::string result;
	if (typeid(_T) == typeid(std::string))
	{
		for (auto& e : thatDataVals) result += e.first + "=" + e.second + "\n";
	}
	else
	{
#ifdef ValStoreLine_Except_On
		throw Except("Not string type");
#endif
	}

	/*
	сделать проверку на существование функции string ToString();
	*/
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetSubNames(std::string name_)
{
	/*Check that @name_ is new. If found - return.*/
	if (thatDataVals.find(name_) != thatDataVals.end()) return;

	/*Split @name_ to @subnames */
	std::vector<std::string> subnames = STR::StrToVec(name_, ".");

	/*Set starting name for inserting new names. It Should be @name_ (begin from end of vector)*/
	std::string name_to_add = name_;

	/*Cycle of adding subnames. Start from full name and on every iteration cuts last part of
	@name_to_add from back of @subnames. Then pop last element. If same name found - return.*/
	while (!subnames.empty())
	{
		/*If element exists - return*/
		if (thatDataVals.find(name_to_add) != thatDataVals.end()) return;

		/*If element does not exist*/
		thatDataVals.insert({ name_to_add, _T() });
		name_to_add = STR::SubStrFromTo(name_to_add, 0, name_to_add.length() - (subnames.back().length() + 1));
		subnames.pop_back();
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> _T ValStoreLineT<_T>::Val(std::string name_)
{
	if (CheckEmpty(name_)) return _T();

	auto it = boost::any_cast<std::map<std::string, _T>::iterator>(CheckExist(name_).Data());
	if (it == thatDataVals.end())	return _T();

	return it->second;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> ValStoreLineT<_T> ValStoreLineT<_T>::ValSubTree(std::string name_)
{
	if (CheckEmpty(name_)) return ValStoreLineT<_T>();

	auto it = boost::any_cast<std::map<std::string, _T>::iterator>(CheckExist(name_).Data());
	if (it == thatDataVals.end())	return ValStoreLineT<_T>();
	
	ValStoreLineT<_T> result;

	/*Cycle of adding nodes to result.
	Node with name = @name_ NOT included.
	Other nodes names do not include @name_*/
	for (auto& e: thatDataVals)
	{
		if (name_.length() > e.first.length()) continue;
		if (name_ == STR::SubStrFromTo(e.first, 0, name_.length()))
		{
			if (name_ == e.first) continue;
			else result.SetVal(STR::SubStrFromTo(e.first, name_.length() + 1), thatDataVals[e.first]);
		}
	}

	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetVal(std::string name_, _T val_)
{
	if (CheckEmpty(name_)) return;

	/*Create new elements, include all subnodes with default values*/
	SetSubNames(name_);

	/*Set value to added node*/
	thatDataVals[name_] = val_;	
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetValSubTree(std::string name_, ValStoreLineT<_T> val_)
{
	/*Preparation: get nodes names. Make @name_ more efficiently usable*/
	std::vector<std::string> names = val_.NodesNamesAll();
	name_ += ".";

	/*Add nodes and values WITHOUT sorting*/
	for (auto& e : names) SetVal(name_ + e, val_.Val(e));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetValSubTree(std::string name_, std::map<std::string, _T> val_)
{
	/*Preparation: make @name_ more efficiently usable*/
	name_ += ".";

	/*Add nodes and values WITHOUT sorting*/
	for (auto& e : val_) SetVal(name_ + e.first, e.second);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::DelVal(std::string name_)
{
	if (CheckEmpty(name_)) return;

	auto it = boost::any_cast<std::map<std::string, _T>::iterator>(CheckExist(name_).Data());
	if (it == thatDataVals.end())	return;

	/*If node is Final then delete node
	If node is not Final and it exists then set it`s val to default*/
	if (IsFinal(name_))	thatDataVals.erase(it);
	else it->second = _T();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::DelValSubTree(std::string name_)
{
	if (CheckEmpty(name_)) return;

	auto it = boost::any_cast<std::map<std::string, _T>::iterator>(CheckExist(name_).Data());
	if (it == thatDataVals.end())	return;

	/*Get node names to delete*/
	std::vector<std::string> found_nodes = NodesNamesAll(name_);
	/*Add root node*/
	found_nodes.push_back("");
	/*Make @name_ more efficient*/
	name_ += ".";
	/*Add root node name to all nodes*/
	for (auto& e : found_nodes) e = name_ + e;
	/*Delete dot from root name*/
	found_nodes.back().pop_back();

	/*delete nodes*/
	for (auto& e : found_nodes) thatDataVals.erase(e);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> std::vector<std::string> ValStoreLineT<_T>::NodesNamesAll(std::string name_ = "")
{
	/*If @name_ is empty get all names*/
	if (name_.empty())
	{
		std::vector<std::string> result;
		for (auto& e : thatDataVals) result.push_back(e.first);
		return result;
	}
	else
	{
		/*if node not found*/
		auto it = boost::any_cast<std::map<std::string, _T>::iterator>(CheckExist(name_).Data());
		if (it == thatDataVals.end())	return std::vector<std::string>();

		/*Create storage*/
		std::vector<std::string> result;

		/*Make @name_ more efficient in searching*/
		name_ += ".";

		/*Check that node names begins with @name_. if so - add to result*/
		for (auto& e : thatDataVals)
		{
			if (name_.length() > e.first.length()) continue;
			if (name_ == STR::SubStrFromTo(e.first, 0, name_.length())) result.push_back(STR::SubStrFromTo(e.first, name_.length()));
		}

		return result;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> std::vector<std::string> ValStoreLineT<_T>::NodesNamesChild(std::string name_ = "")
{
	if (name_.empty())
	{
		/*If looking from root`s children then all its nearest children dont have dot in name*/
		std::vector<std::string> result;
		for (auto& e : thatDataVals)	if (e.first.find(".") == std::string::npos) result.push_back(e.first);

		return result;
	}
	else
	{
		/*if node not found*/
		auto it = boost::any_cast<std::map<std::string, _T>::iterator>(CheckExist(name_).Data());
		if (it == thatDataVals.end())	return std::vector<std::string>();

		/*Make @name_ more efficient in searching*/
		name_ += ".";

		/*Find and add to result node names begins with @name_*/
		std::vector<std::string> result;
		for (auto& e : thatDataVals)
		{
			if (name_.length() > e.first.length()) continue;
			if (name_ == STR::SubStrFromTo(e.first, 0, name_.length())) result.push_back(STR::SubStrFromTo(e.first, name_.length()));
		}

		/*Cut names*/
		size_t fd;
		for (auto& e : result)
		{
			fd = e.find(".");
			e = e.substr(0, fd);
		}

		/*delete same*/
		std::sort(result.begin(), result.end());
		std::vector<std::string> res = { result.back() };
		while (!result.empty())
		{
			if (result.back() == res.back()) result.pop_back();
			else res.push_back(result.back());
		}

		return res;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> bool ValStoreLineT<_T>::IsFinal(std::string name_)
{
	if (CheckEmpty(name_)) return false;
	if (boost::any_cast<std::map<std::string, _T>::iterator>(CheckExist(name_).Data()) == thatDataVals.end())	return true;

	/*Make @name_ more efficient in searching*/
	name_ += ".";

	/*Check if node begins with new @name_ exists. If so - NOT Final*/
	for (auto& e : thatDataVals)
	{
		if (name_.length() > e.first.length()) continue;
		if (name_ == STR::SubStrFromTo(e.first, 0, name_.length())) return false;
	}

	/*else - Final*/
	return true;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::Clear()
{
	thatDataVals.clear();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------