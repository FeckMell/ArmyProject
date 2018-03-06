#pragma once
#include "stdafx.h"

class MathOperations
{
private:

	typedef std::string string;

	string thatSymbol = "";
	unsigned thatPriority = 0;
	bool thatBinary = 0;

public:

	string Symbol() { return thatSymbol; }
	unsigned Priority() { return thatPriority; }
	bool IsBinary() { return thatBinary; }
	bool IsSet();

	MathOperations(string symbol_, unsigned priority_, bool binary_, boost::any func_);
	MathOperations() {}
	~MathOperations() {}
};

