#pragma once
#include "stdafx.h"

class MathOperations
{
private:

	typedef std::string string;

public:

	unsigned Priority();
	bool IsBinary();
	bool IsSet();

	MathOperations(string symbol_, unsigned priority_, bool binary_, boost::any func_);
	MathOperations() {}
	~MathOperations() {}
};

