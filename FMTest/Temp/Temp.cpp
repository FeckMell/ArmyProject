// Temp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <boost\function.hpp>
using namespace std;

vector<size_t> FindInStrAll(string target_, string what_)
{
	vector<size_t> result;
	if (what_.empty()) return result;
	size_t length = what_.length();
	size_t fd = target_.find(what_);
	while (fd != string::npos)
	{
		result.push_back(fd);
		fd = target_.find(what_, fd + 1);
	}
	return result;
}
string SubStrFromTo(string target_, size_t from_, size_t to_)
{
	if (from_ >= target_.length()) return "";
	if (from_ >= to_) return "";
	if (to_>target_.length()) return 	target_.substr(from_);
	else return target_.substr(from_, to_ - from_);
}

int main(int argc, char* argv[])
{
	string thatExpressionSTR = "(( ( aa(bb (cc(dd ";
	cout << SubStrFromTo(thatExpressionSTR, 0, 2);


	system("pause");
	return 0;
}

