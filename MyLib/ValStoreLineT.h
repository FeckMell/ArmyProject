#pragma once
#include "stdafx.h"
#include "Str.h"

template<class _T> class ValStoreLineT
{
private:

	typedef ValStoreLineT VSLT;
	typedef std::string string;

	void SetSubNames(string name_);

	std::map<string, _T> thatDataVals;
	std::vector<string> thatDataNames;

public:

	string ToString();
	string PrintAll();
	ValStoreLineT() {}

	_T Val(string name_);
	void SetVal(string name_, _T val_);
	void DelVal(string name_);

	VSLT ValSubTree(string name_);
	void SetValSubTree(string name_, VSLT val_);
	void DelValSubTree(string name_);
};

//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> std::string  ValStoreLineT<_T>::ToString()
{
	string result;
	if ( typeid(_T) == typeid(string) )
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
template<class _T> void ValStoreLineT<_T>::SetSubNames(string name_)
{
	if ( find(thatDataNames.begin(), thatDataNames.end(), name_) != thatDataNames.end() ) return;

	auto v = STR::StrToVec(name_, ".");
	std::string name_tmp = name_;
	for ( unsigned i = v.size() - 1; i <v.size(); --i )
	{
		if ( find(thatDataNames.begin(), thatDataNames.end(), name_tmp) != thatDataNames.end() ) return;

		thatDataNames.push_back(name_tmp);
		thatDataVals.insert({ name_tmp, _T() });
		name_tmp = STR::SubStrFromTo(name_tmp, 0, name_tmp.length() - (v[i].length() + 1));
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> _T ValStoreLineT<_T>::Val(string name_)
{
	if ( name_.empty() ) return _T();
	auto it = thatDataVals.find(name_);
	if ( it == thatDataVals.end() ) return _T();
	else return it->second;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::SetVal(string name_, _T val_)
{
	if ( name_.empty() ) return;
	SetSubNames(name_);
	thatDataVals[name_] = val_;
	sort(thatDataNames.begin(), thatDataNames.end());
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> void ValStoreLineT<_T>::DelVal(string name_)
{
	if ( name_.empty() ) return;
	thatDataVals.erase(name_);
	thatDataNames.erase(remove(thatDataNames.begin(), thatDataNames.end(), name_), thatDataNames.end());
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class _T> ValStoreLineT<_T> ValStoreLineT<_T>::ValSubTree(string name_)
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
template<class _T> void ValStoreLineT<_T>::SetValSubTree(string name_, ValStoreLineT<_T> val_)
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
template<class _T> void ValStoreLineT<_T>::DelValSubTree(string name_)
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