// Experiments.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

wstring ToWString(string s_)
{
	wchar_t* wc = new wchar_t[s_.length()];
	mbstowcs(wc, s_.c_str(), s_.length());
	wstring result(wc);
	delete wc;
	return result;
}

int main()
{
	string s = "fucker";
	system("pause");
	return 0;
}

