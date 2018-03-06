#pragma once
#include "stdafx.h"
#include "Str.h"
class ValStoreTreeEntry
{
private:

	typedef ValStoreTreeEntry VSTE;
	typedef std::string string;

	string thatName;
	string thatData;
	std::map<string, VSTE> thatDataTree;

public:
	///**/void SetName(string name_) { thatName = name_; }
	/**/string NodeName() { return thatName; }
	string ToString(string path_);
	string PrintAll(unsigned lvl_);

	ValStoreTreeEntry() {}
	ValStoreTreeEntry(string name_);

	string Val(std::vector<string> name_, unsigned& lvl_);
	void SetVal(std::vector<string> name_, unsigned& lvl_, string val_);
	void DelVal(std::vector<string> name_, unsigned& lvl_);

	VSTE ValSubTree(std::vector<string> name_, unsigned& lvl_);
	void SetValSubTree(std::vector<string> name_, unsigned& lvl_, VSTE val_);
	void DelValSubTree(std::vector<string> name_, unsigned& lvl_);

	std::map<string, VSTE> ChildNodes(std::vector<string> name_, unsigned& lvl_);
	std::vector<string> ChildNodesNames(std::vector<string> name_, unsigned& lvl_);

};

