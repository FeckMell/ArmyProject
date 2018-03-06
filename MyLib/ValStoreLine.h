#pragma once
#include "stdafx.h"
#include "Str.h"

class ValStoreLine
{
private:

	typedef ValStoreLine VSL;
	typedef std::string string;

	void SetSubNames(string name_);

	std::map<string, string> thatDataVals;
	std::vector<string> thatDataNames;

public:

	string ToString();
	string PrintAll();
	ValStoreLine() {}

	string Val(string name_);
	void SetVal(string name_, string val_);
	void DelVal(string name_);

	VSL ValSubTree(string name_);
	void SetValSubTree(string name_, VSL val_);
	void DelValSubTree(string name_);

};