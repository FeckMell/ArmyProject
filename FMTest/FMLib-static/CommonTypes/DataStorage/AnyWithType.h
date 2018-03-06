#pragma once
#include "stdafx.h"

class AnyWithType
{
private:

	static std::map<std::string, unsigned> FromStrToUns;
	static std::map<unsigned, std::string> FromUnsToStr;

	boost::any thatData = "";
	std::string thatDataTypeS = "NONE";
	unsigned thatDataTypeU = 0;

public:
	
	enum TypeList { NONE, BOOL, INT, STRING, DOUBLE, UNSIGNED, OTHER, MaxType };

	AnyWithType(boost::any data_, std::string type_);
	AnyWithType(boost::any data_, unsigned type_);
	AnyWithType() {}

	boost::any Data();
	std::string TypeS();
	unsigned TypeU();

	void Set(boost::any data_, std::string type_);
	void Set(boost::any data_, unsigned type_);

};

