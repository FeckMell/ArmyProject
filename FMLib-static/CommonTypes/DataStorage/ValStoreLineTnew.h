#pragma once
#include "stdafx.h"
#include "CommonTypes\Except.h"
#include "Interfaces/Str.h"

#define ValStoreLineT_Sorting_Off

/*
Except:
"Empty node name"
"Node not found"
*/
template<class _T> class ValStoreLineT
{
private:

	void SetValPrivate(std::string name_, _T val_);
	void SetSubNames(std::string name_);
#ifndef ValStoreLineT_Sorting_Off 
	void SetSubNamesSorted(std::string name_);
#endif

	std::map<std::string, _T> thatDataVals;
	std::vector<std::string> thatDataNames;

public:

	std::string ToString();
	std::string PrintAll();
	ValStoreLineT() {}

	std::vector<std::string> NodesNamesAll(std::string name_ = "");
	std::vector<std::string> NodesNamesChild(std::string name_ = "");
	bool IsFinal(std::string name_);
	//unsigned NodesNum(std::string name_);

	_T Val(std::string name_);
	ValStoreLineT<_T> ValSubTree(std::string name_);

	void SetVal(std::string name_, _T val_);
	void SetValSubTree(std::string name_, ValStoreLineT<_T> val_);
	void SetValSubTree(std::string name_, std::map<std::string, _T> val_);

	void DelVal(std::string name_);
	void DelValSubTree(std::string name_);

};

//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetValPrivate(std::string name_, _T val_)
{
	if (name_.empty()) throw Except("Empty node name");

	/*Create and sort new elements, include all subnodes with default values*/
	SetSubNames(name_);
	/*Set value to added node*/
	thatDataVals[name_] = val_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetSubNames(std::string name_)
{
	/*Check that @name_ is new. If found - return.*/
	if (find(thatDataNames.begin(), thatDataNames.end(), name_) != thatDataNames.end()) return;

	/*Split @name_ to @subnames */
	std::vector<std::string> subnames = STR::StrToVec(name_, ".");

	/*Set starting name for inserting new names. It Should be @name_ (begin from end of vector)*/
	std::string name_to_add = name_;

	/*Cycle of adding subnames. Start from full name and on every iteration cuts last part of
	@name_to_add from back of @subnames. Then pop last element. If same name found - return.*/
	while (!subnames.empty())
	{
		/*If element exists - return*/
		if (find(thatDataNames.begin(), thatDataNames.end(), name_to_add) != thatDataNames.end()) return;

		/*If element does not exist*/
		thatDataNames.push_back(name_to_add);
		thatDataVals.insert({ name_to_add, _T() });
		name_to_add = STR::SubStrFromTo(name_to_add, 0, name_to_add.length() - (subnames.back().length() + 1));
		subnames.pop_back();
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
#ifndef ValStoreLineT_Sorting_Off
template<class _T> void ValStoreLineT<_T>::SetSubNamesSorted(std::string name_)
{
	/*Check that @name_ is new. If found - return.*/
	if (find(thatDataNames.begin(), thatDataNames.end(), name_) != thatDataNames.end()) return;

	/*Split @name_ to @subnames */
	std::vector<std::string> subnames = STR::StrToVec(name_, ".");

	/*Set starting name for inserting new names. It Should be @name_ (begin from end of vector)*/
	std::string name_to_add = name_;

	/*Cycle of adding subnames. Start from full name and on every iteration cuts last part of
	@name_to_add from back of @subnames. Then pop last element. If same name found - return.*/
	while (!subnames.empty())
	{
		/*If element exists - return*/
		if (find(thatDataNames.begin(), thatDataNames.end(), name_to_add) != thatDataNames.end()) return;

		/*If element does not exist*/
		thatDataNames.push_back(name_to_add);
		thatDataVals.insert({ name_to_add, _T() });
		name_to_add = STR::SubStrFromTo(name_to_add, 0, name_to_add.length() - (subnames.back().length() + 1));
		subnames.pop_back();
	}

	/*Sort node`s names*/
	sort(thatDataNames.begin(), thatDataNames.end());
}
#endif
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> _T ValStoreLineT<_T>::Val(std::string name_)
{
	if (name_.empty()) throw Except("Empty node name");
	auto it = thatDataVals.find(name_);
	if (it == thatDataVals.end()) throw Except("Node not found");

	return it->second;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> ValStoreLineT<_T> ValStoreLineT<_T>::ValSubTree(std::string name_)
{
	/*Extrem ocasions*/
	if (name_.empty()) throw Except("Empty node name");
	if (thatDataVals.find(name_) == thatDataVals.end()) throw Except("Node not found");

	ValStoreLineT<_T> result;

	/*Cycle of adding nodes to result.
	Node with name = @name_ NOT included.
	Other nodes names do not include @name_*/
	for (auto& e: thatDataNames)
	{
		if (name_.length() > e.length()) continue;
		if (name_ == STR::SubStrFromTo(e, 0, name_.length())
		{
			if (name_ == e) continue;
			else result.SetValPrivate(STR::SubStrFromTo(e, name_.length() + 1), thatDataVals(e));
		}
	}
#ifndef ValStoreLineT_Sorting_Off
	/*Sort result node names*/
	sort(result.thatDataNames.begin(), result.thatDataNames.end());
#endif

	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetVal(std::string name_, _T val_)
{
	if (name_.empty()) throw Except("Empty node name");

	/*Create and sort new elements, include all subnodes with default values*/
#ifndef ValStoreLineT_Sorting_Off
	SetSubNamesSorted(name_);
#else
	SetSubNames(name_);
#endif

	/*Set value to added node*/
	thatDataVals[name_] = val_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetValSubTree(std::string name_, ValStoreLineT<_T> val_)
{
	/*Preparation: get nodes names. Make @name_ more efficiently usable*/
	std::vector<std::string> names = val_.NodesNames();
	name_ += ".";

	/*Add nodes and values WITHOUT sorting*/
	for (auto& e : names) SetValPrivate(name_ + e, val_.Val(e));

#ifndef ValStoreLineT_Sorting_Off
	/*Sort node`s names*/
	sort(thatDataNames.begin(), thatDataNames.end());
#endif
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetValSubTree(std::string name_, std::map<std::string, _T> val_)
{
	/*Preparation: make @name_ more efficiently usable*/
	name_ += ".";

	/*Add nodes and values WITHOUT sorting*/
	for (auto& e : val_) SetValPrivate(name_ + e.first, e.second);

#ifndef ValStoreLineT_Sorting_Off
	/*Sort node`s names*/
	sort(thatDataNames.begin(), thatDataNames.end());
#endif
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::DelVal(std::string name_)
{
	if (name_.empty()) throw Except("Empty node name");

	/*If node is Final then delete node*/
	if (IsFinal())
	{
		thatDataVals.erase(name_);
		thatDataNames.erase(remove(thatDataNames.begin(), thatDataNames.end(), name_), thatDataNames.end());
		return;
	}

	/*If node is not Final and it exists then set it`s val to default*/
	auto it = thatDataVals.find(name_);
	if (it != thatDataVals.end()) 
	{
		(*it)->second = _T();		
		return;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::DelValSubTree(std::string name_)
{
	if (name_.empty()) throw Except("Empty node name");

	/*Create storage for nodes names to delete*/
	std::vector<std::string> found_nodes;

	/*find all nodes to delete*/
	for (auto& e : thatDataNames)
	{
		if (name_.length() > e.length()) continue;
		if (STR::SubStrFromTo(e, 0, name_.length()) == name_)	found_nodes.push_back(e);
	}

	/*delete nodes*/
	for (auto& e : found_nodes)
	{
		thatDataVals.erase(e);
		thatDataNames.erase(remove(thatDataNames.begin(), thatDataNames.end(), e), thatDataNames.end());
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> std::vector<std::string> ValStoreLineT<_T>::NodesNamesAll(std::string name_ = "")
{
	if (name_.empty()) return thatDataNames;
	else
	{
		/*Create storage*/
		std::vector<std::string> result;

		/*Make @name_ more efficient in searching*/
		name_ += ".";

		/*Check that node names begins with @name_. if so - and to result*/
		for (auto& e : thatDataNames)
		{
			if (name_.length() > e.length()) continue;
			if (name_ == STR::SubStrFromTo(e, 0, name_.length()) result.push_back(STR::SubStrFromTo(e, name_.length());
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
		for (auto& e : thatDataNames)	if (e.find(".") == std::string::npos) result.push_back(e);

		return result;
	}
	else
	{
		/*Make @name_ more efficient in searching*/
		name_ += ".";

		/*Find and add to result node names begins with @name_*/
		std::vector<std::string> result;
		for (auto& e : thatDataNames)
		{
			if (name_.length() > e.length()) continue;
			if (name_ == STR::SubStrFromTo(e, 0, name_.length())) result.push_back(STR::SubStrFromTo(e, name_.length());
		}

		return result;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> bool ValStoreLineT<_T>::IsFinal(std::string name_)
{
	if (name_.empty()) throw Except("Empty node name");
	if (thatDataVals.find(name_) == thatDataVals.end()) throw Except("Node not found");

	/*Make @name_ more efficient in searching*/
	name_ += ".";

	/*Check if node begins with new @name_ exists. If so - NOT Final*/
	for (auto& e : thatDataNames)
	{
		if (name_.length() > e.length()) continue;
		if (name_ == STR::SubStrFromTo(e, 0, name_.length()) return false;
	}

	/*else - Final*/
	return true;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------




































template<class _T> std::string  ValStoreLineT<_T>::ToString()
{
	std::string result;
	if (typeid(_T) == typeid(std::string))
	{
		for ( auto& e : thatDataVals ) result += e.first + "=" + e.second + "\n";
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
	if (find(thatDataNames.begin(), thatDataNames.end(), name_) != thatDataNames.end()) return;

	/*Split @name_ to @subnames */
	std::vector<std::string> subnames = STR::StrToVec(name_, ".");

	/*Set starting name for inserting new names. It Should be @name_ (begin from end of vector)*/
	std::string name_to_add = name_;

	/*Cycle of adding subnames. Start from full name and on every iteration cuts last part of 
	@name_to_add from back of @subnames. Then pop last element. If same name found - return.*/
	while (!subnames.empty())
	{
		if (find(thatDataNames.begin(), thatDataNames.end(), name_to_add) != thatDataNames.end()) return;
		thatDataNames.push_back(name_to_add);
		thatDataVals.insert({ name_to_add, _T() });
		name_to_add = STR::SubStrFromTo(name_to_add, 0, name_to_add.length() - (subnames.back().length() + 1));
		subnames.pop_back();
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> _T ValStoreLineT<_T>::Val(std::string name_)
{
	if ( name_.empty() ) return _T();
	auto it = thatDataVals.find(name_);
	if ( it == thatDataVals.end() ) return _T();
	else return it->second;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetVal(std::string name_, _T val_)
{
	if ( name_.empty() ) return;
	SetSubNames(name_);
	thatDataVals[name_] = val_;
	sort(thatDataNames.begin(), thatDataNames.end());
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::DelVal(std::string name_)
{
	if ( name_.empty() ) return;
	thatDataVals.erase(name_);
	thatDataNames.erase(remove(thatDataNames.begin(), thatDataNames.end(), name_), thatDataNames.end());
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> ValStoreLineT<_T> ValStoreLineT<_T>::ValSubTree(std::string name_)
{
	ValStoreLineT<_T> result;
	if ( name_.empty() )
	{
		result.thatDataNames = thatDataNames;
		result.thatDataVals = thatDataVals;
		return result;
	}
	bool root = true;
	std::string name_root = STR::SubStrFromTo(name_, name_.find_last_of(".") + 1, std::string::npos);
	std::string name_cut;
	auto it = find(thatDataNames.begin(), thatDataNames.end(), name_);
	while ( 1 )
	{
		if ( it == thatDataNames.end() ) break; // if not found
		if ( STR::SubStrFromTo(*it, 0, name_.length()) != name_ ) break; // if name doesnt begin with name_


		name_cut = name_root + STR::SubStrFromTo(*it, name_.length() + 1, std::string::npos);
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
template<class _T> void ValStoreLineT<_T>::SetValSubTree(std::string name_, ValStoreLineT<_T> val_)
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
template<class _T> void ValStoreLineT<_T>::SetValSubTree(std::string node_name_, std::map<std::string, _T> val_)
{
	for (auto& e : val_)
	{
		if (e.)
	}
	/*if (name_.empty()) return;
	SetSubNames(name_);
	thatDataVals[name_] = val_;
	sort(thatDataNames.begin(), thatDataNames.end());*/
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::DelValSubTree(std::string name_)
{
	if ( name_.empty() ) return;
	stack<string> found;
	for (auto& e : thatDataNames)
	{
		if (e.length() < name_.length()) continue;
		if (STR::SubStrFromTo(e, 0, name_.length()) == name_)	found.push(e);
	}
	while (!found.empty())
	{
		thatDataVals.erase(found.top());
		thatDataNames.erase(remove(thatDataNames.begin(), thatDataNames.end(), found.top()), thatDataNames.end());
		found.pop();
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------