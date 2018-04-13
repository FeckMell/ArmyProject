#pragma once
#include "stdafx.h"
#include <Parsers\Other\Army.h>

using namespace std;

class ReadFile
{
public:

	static void ReadFilter(string filepath_);
	static string GetFilter();

	static void ReadData(string filepath_);
	static vector<string>* GetData();
	static void FreeData();

	static void ParseData(vector<Army>& result_);



private:

	static string thatFilterSTR;
	static vector<string>	thatData;

	ReadFile(){}
	~ReadFile(){}
};

