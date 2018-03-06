#pragma once
#include "stdafx.h"
#include "ValStoreTreeEntry.h"
#include "Str.h"

class ValStoreTree
{

private:

	typedef ValStoreTree VST;
	typedef ValStoreTreeEntry VSTE;
	typedef std::string string;

	std::map<string, VSTE> thatData;

public:

	string Val(string name_);
	void SetVal(string name_, string val_);
	void DelVal(string name_);

	VST ValSubTree(string name_);
	void SetValSubTree(string name_, VST val_);
	void DelValSubTree();

	std::vector<string> ChildNodesOf();
	string ParentOf();
	string PrintAll();


};
