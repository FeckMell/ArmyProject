// Temp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <regex>
#include <boost\function.hpp>
#include <boost\any.hpp>
using namespace std;



int main(int argc, char* argv[])
{
	auto begin = chrono::steady_clock::now();
	this_thread::sleep_for(chrono::minutes(2));
	this_thread::sleep_for(chrono::seconds(3));
	this_thread::sleep_for(chrono::milliseconds(156));
	auto end = chrono::steady_clock::now();

	//chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - begin);
	auto H = chrono::duration_cast<chrono::hours>(end - begin);
	auto M = chrono::duration_cast<chrono::minutes>(end - begin) - H;
	auto S = chrono::duration_cast<chrono::seconds>(end - begin) - H - M;
	auto MS = chrono::duration_cast<chrono::milliseconds>(end - begin) -H -M -S;
	cout << "H:" << H.count() << "\nM:" << M.count() << "\nS:" << S.count() << "\nMS:" << MS.count();
	system("pause");
	return 0;
}

