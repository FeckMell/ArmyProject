// Filter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ReadFile.h"
#include <Interfaces\CFG.h>
#include <Calculation\Math\RevPolNotation.h>
#include "Process.h"
#include "Time.h"

using namespace std;


int main(int argc, char* argv[])
{
	/*Params*/
	string file_in = "C:\\WORK\\FMLib\\Filter\\passport1000.txt";
	string experssion_in = "C:\\WORK\\FMLib\\Filter\\Filter_expression.txt";
	string result = "C:\\WORK\\FMLib\\Filter\\result.txt";

	/*init filter*/
	ReadFile::ReadFilter(experssion_in);
	RevPolNotation rpn(ReadFile::GetFilter());
	cout << "Filter RPN:" << rpn.ToString() << "\n";

	/*Prepare data*/
	ReadFile::ReadData(file_in);
	vector<Army> v_army;
	ReadFile::ParseData(v_army);

	/*Filter data and write result*/
	Process::Init(result);
	Time::StartWithTime(boost::bind(&Process::Filter, rpn, v_army));
	Process::PrintFiltered(v_army, file_in, experssion_in);
	
	/*Free*/
	ReadFile::FreeData();
	cout << "\n";
	system("pause");
	return 0;
}

