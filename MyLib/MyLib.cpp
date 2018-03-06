// MyLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Str.h"
#include "CFG.h"
#include "LOG.h"
#include "ValStoreTreeEntry.h"
#include "ValStoreTree.h"
#include "LogicOperations.h"
#include "ValStoreLine.h"
#include "ValStoreLineT.h"
#include "RevPolNotation.h"
//#include "Evulation2.h"
//#include "Operation.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	string exit;
	int i = 4;
	//auto o = Operation::Get("==");
	
	
	/*RevPolNotation::Init();
	string s = "aaa != (bb>=c <=f>= h) contains g";
	RevPolNotation r(s);
	r.TestPrint2();

	s = "aaa != bb>=c <=f>= h contains g";
	RevPolNotation r2(s);
	r2.TestPrint2();*/
	
	//CFG::Init("C:\\WORK\\MyLib\\Release\\fff.exe");
	//CFG::InitWithDefaults("C:\\WORK\\MyLib\\Release\\fff.exe", m);
	//LOG::Init({"Log"});


	cin >> exit;
	system("pause");
	return 0;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
