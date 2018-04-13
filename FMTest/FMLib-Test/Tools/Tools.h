#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"

class Tools
{
public:

	static std::wstring ToWString(std::string s_);
	static std::vector<std::vector<std::string>> ReadTestData(std::string path_, unsigned size_);

	static void RecurCall(unsigned i_, boost::function<unsigned(unsigned)> f_i_change, boost::function<bool(unsigned)> f_if,
		boost::function<void(unsigned)> f_true, boost::function<void(unsigned, boost::any)> f_catch);


	Tools(){}
	~Tools(){}
};

