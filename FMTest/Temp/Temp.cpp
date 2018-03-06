// Temp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <boost\function.hpp>
#include <boost\any.hpp>
using namespace std;

//template<class q, class w> boost::function<void(q, w, w)> that;

void use_e(bool& r, unsigned x, unsigned y){	r = (x == y);}
void use_o(bool& r, bool x, bool y){ r = (x || y); }
void use_f(bool& r, string x, string y){ r = (x.find(y) != string::npos); }



int main(int argc, char* argv[])
{
	string s = " ( N:NetReceiver.Port==U:10000)||N:ModemHeaderPleyada.Time!=U:235284270";
	if (s.front() == ' ') s.erase(s.begin());
	cout << "_" << s;
	system("pause");
	return 0;
}

