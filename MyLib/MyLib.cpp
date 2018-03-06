// MyLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Str.h"
#include "CFG.h"
#include "LOG.h"
//#include "old_ValStoreTree.h"
#include "ValStoreTreeEntry.h"
#include "ValStoreTree.h"

using namespace std;
void testVSTE();

int main()
{
	setlocale(LC_ALL, "Russian");
	string exit;
	cout<<"\n_"<< STR::SubStrFromTo("aaa", 2, 100)<<"_";
	
	//CFG::Init("C:\\WORK\\MyLib\\Release\\fff.exe");
	//LOG::Init({"Log"});
	//testVSTE();
	

	/*ValStoreTree vst;
	vst.SetVal("1", "val 0");
	vst.SetVal("1.2.3.4", "val 1");
	vst.SetVal("1.2.3.5", "val 2");
	vst.SetVal("1.2.3.6", "val 3");
	vst.SetVal("1.2.3.6", "val 4");
	vst.SetVal("1.2.4.5", "val 5");
	vst.SetVal("1.2.4.6", "val 6");
	vst.SetVal("1.2.5.6", "val 7");
	vst.SetVal("1.2.5.6", "val 8");
	vst.SetVal("2.3.4.5", "val 9");
	cout << "\n\nPRINT ALL:\n" << vst.PrintAll();*/
	
	//vst.DelVal("7");
	//cout << "\n\nPRINT ALL:\n" << vst.PrintAll();
	//auto z = vst.ValSubTree("2");
	//cout << "\n\nPRINT ALL:\n" << z.PrintAll();
	//vst.SetValSubTree("", z);
	//cout << "\n\nPRINT ALL:\n" << vst.PrintAll();
	/*vst.DelValSubTree("1.2.3");
	cout << "\n\nPRINT ALL:\n" << vst.PrintAll();*/


	cin >> exit;
	system("pause");
	return 0;
}

void testVSTE_PrintAll(ValStoreTreeEntry& VSTE)
{
	unsigned lvl;
	lvl = 0; cout << "\n\nPRINTALL:\n" << VSTE.NodeName() << "=" << VSTE.PrintAll(lvl);
}
void testVSTE_SetVal(ValStoreTreeEntry& VSTE)
{
	unsigned lvl;

	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq", "."), lvl, "val 10");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.eee.rrr.rrr", "."), lvl, "val 1");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.eee.rrr.ttt", "."), lvl, "val 2");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.eee.rrr.yyy", "."), lvl, "val 3");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.eee.rrr.uuu", "."), lvl, "val 4");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.eee.aaa.sss", "."), lvl, "val 5");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.eee.aaa.ddd", "."), lvl, "val 6");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.eee.aaa.fff", "."), lvl, "val 7");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.hhh.jjj.ttt", "."), lvl, "val 8");
	lvl = 0; VSTE.SetVal(STR::StrToVec("qqq.www.hhh.kkk.lll", "."), lvl, "val 9");
	testVSTE_PrintAll(VSTE);
}
void testVSTE_SetSubTree(ValStoreTreeEntry& VSTE, ValStoreTreeEntry& z)
{
	unsigned lvl;

	lvl = 0; VSTE.SetValSubTree(STR::StrToVec("qqq.www.eee.aaa.ddd", "."), lvl, z);
}
void testVSTE_SubTree(ValStoreTreeEntry& VSTE)
{
	unsigned lvl;

	lvl = 0; auto z = VSTE.ValSubTree(STR::StrToVec("qqq.www.eee", "."), lvl);
	testVSTE_PrintAll(z);

	testVSTE_SetSubTree(VSTE, z);
	testVSTE_PrintAll(VSTE);
}
void testVSTE_DelValSubTree(ValStoreTreeEntry& VSTE)
{
	unsigned lvl;
	lvl = 0; VSTE.DelValSubTree(STR::StrToVec("qqq.www.eee.rrr.yyy", "."), lvl);
	testVSTE_PrintAll(VSTE);
}
void testVSTE_ChildNodes(ValStoreTreeEntry& VSTE)
{
	unsigned lvl;
	lvl = 0; auto z = VSTE.ChildNodes(STR::StrToVec("qqq.www.eee.rrr", "."), lvl);
	for ( auto& e : z )
	{
		lvl = 0; cout << "\n\nPRINTALL:\n" << e.second.NodeName() << "=" << e.second.PrintAll(lvl);
	}
}
void testVSTE_ChildNodesNames(ValStoreTreeEntry& VSTE)
{
	unsigned lvl;
	lvl = 0; auto z = VSTE.ChildNodesNames(STR::StrToVec("qqq.www.eee.rrr", "."), lvl);
	for ( auto& e : z ) {lvl = 0; cout << "\n\nPRINTALL:\n" << e;	}
}
void testVSTE_DelVal(ValStoreTreeEntry& VSTE)
{
	unsigned lvl;
	lvl = 0; VSTE.DelVal(STR::StrToVec("qqq", "."), lvl);
	testVSTE_PrintAll(VSTE);
}
void testVSTE()
{
	ValStoreTreeEntry VSTE("qqq");

	testVSTE_SetVal(VSTE);
	testVSTE_DelVal(VSTE);


	
}

