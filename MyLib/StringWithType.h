#pragma once
#include "stdafx.h"
class StringWithType
{
private:

	static std::map<std::string, unsigned> FromStrToUns;
	static std::map<unsigned, std::string> FromUnsToStr;

	std::string thatData = "";
	std::string thatDataTypeS = "NONE";
	unsigned thatDataTypeU = 0;

public:

	enum TypeList { NONE, BOOL, INT, STRING };

	StringWithType(std::string data_, std::string type_);
	StringWithType(std::string data_, unsigned type_);
	StringWithType() {}

	std::string Data();
	std::string TypeS();
	unsigned TypeU();

	void Set(std::string data_, std::string type_);
	void Set(std::string data_, unsigned type_);

};

