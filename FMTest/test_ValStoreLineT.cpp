#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "CommonTypes\ValStoreLineT.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FMTest
{
	TEST_CLASS(test_ValStoreLineT)
	{
	public:

		/*TEST_METHOD(SelfTest)
		{
		auto v = Tools::ReadTestData("../FMTest/TestData/STR/StrInBetween.txt", 4);
		}			*/
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(Constructor)
		{
			string test_file = "../FMTest/TestData/ValStoreLineT/Constructor.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(SetVal)
		{
			string test_file = "../FMTest/TestData/ValStoreLineT/SetVal.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				vector<string> names_in = STR::StrToVec(test_data[j][0], "#");
				vector<string> values_in = STR::StrToVec(test_data[j][1], "#");
				vector<string> names_out = STR::StrToVec(test_data[j][2], "#");
				vector<string> values_out = STR::StrToVec(test_data[j][3], "#");
				Assert::AreEqual(names_in.size(), values_in.size(), Tools::ToWString("Error in file: sizes IN are different!").c_str());
				Assert::AreEqual(names_out.size(), values_out.size(), Tools::ToWString("Error in file: sizes OUT are different!").c_str());

				ValStoreLineT<string> V;
				for (unsigned i = 0; i < names_in.size(); ++i) V.SetVal(names_in[i], values_in[i]);
				for (unsigned i = 0; i < names_out.size(); ++i) Assert::AreEqual(values_out[i], V.Val(names_out[i]),
					Tools::ToWString("i=" + to_string(i) + " name_out=" + names_out[i] + " values_out=" + values_out[i]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(DelVal)
		{
			string test_file = "../FMTest/TestData/ValStoreLineT/DelVal.txt";
			auto test_data = Tools::ReadTestData(test_file, 5);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				vector<string> names_in = STR::StrToVec(test_data[j][0], "#");
				vector<string> values_in = STR::StrToVec(test_data[j][1], "#");
				vector<string> names_del = STR::StrToVec(test_data[j][2], "#");
				vector<string> names_out = STR::StrToVec(test_data[j][3], "#");
				vector<string> values_out = STR::StrToVec(test_data[j][4], "#");
				Assert::AreEqual(names_in.size(), values_in.size(), Tools::ToWString("Error in file: sizes IN are different!").c_str());
				Assert::AreEqual(names_out.size(), values_out.size(), Tools::ToWString("Error in file: sizes OUT are different!").c_str());

				ValStoreLineT<string> V;
				for (unsigned i = 0; i < names_in.size(); ++i) V.SetVal(names_in[i], values_in[i]);
				for (unsigned i = 0; i < names_del.size(); ++i) V.DelVal(names_del[i]);
				for (unsigned i = 0; i < names_out.size(); ++i) Assert::AreEqual(values_out[i], V.Val(names_out[i]),
					Tools::ToWString("i=" + to_string(i) + " name_out=" + names_out[i] + " values_out=" + values_out[i]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------ ValSubTree
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(ValSubTree)
		{
			string test_file = "../FMTest/TestData/ValStoreLineT/ValSubTree.txt";
			auto test_data = Tools::ReadTestData(test_file, 5);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				vector<string> names_in = STR::StrToVec(test_data[j][0], "#");
				vector<string> values_in = STR::StrToVec(test_data[j][1], "#");
				string name_cut = test_data[j][2];
				vector<string> names_out = STR::StrToVec(test_data[j][3], "#");
				vector<string> values_out = STR::StrToVec(test_data[j][4], "#");
				Assert::AreEqual(names_in.size(), values_in.size(), Tools::ToWString("Error in file: sizes IN are different!").c_str());
				Assert::AreEqual(names_out.size(), values_out.size(), Tools::ToWString("Error in file: sizes OUT are different!").c_str());

				ValStoreLineT<string> V;
				for (unsigned i = 0; i < names_in.size(); ++i) V.SetVal(names_in[i], values_in[i]);
				ValStoreLineT<string> V_1 = V.ValSubTree(name_cut);
				for (unsigned i = 0; i < names_out.size(); ++i)
				{
					Assert::AreEqual(values_out[i], V_1.Val(names_out[i])/*,
						Tools::ToWString(res"i=" + to_string(i) + " name_out=" + names_out[i] + " values_out=" + values_out[i]).c_str()*/);
				}
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(DelValSubTree)
		{
			string test_file = "../FMTest/TestData/ValStoreLineT/DelValSubTree.txt";
			auto test_data = Tools::ReadTestData(test_file, 5);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				vector<string> names_in = STR::StrToVec(test_data[j][0], "#");
				vector<string> values_in = STR::StrToVec(test_data[j][1], "#");
				string name_cut = test_data[j][2];
				vector<string> names_out = STR::StrToVec(test_data[j][3], "#");
				vector<string> values_out = STR::StrToVec(test_data[j][4], "#");

				Assert::AreEqual(names_in.size(), values_in.size(), Tools::ToWString("Error in file: sizes IN are different!").c_str());
				Assert::AreEqual(names_out.size(), values_out.size(), Tools::ToWString("Error in file: sizes OUT are different!").c_str());

				ValStoreLineT<string> V;
				for (unsigned i = 0; i < names_in.size(); ++i) V.SetVal(names_in[i], values_in[i]);
				V.DelValSubTree(name_cut);
				for (unsigned i = 0; i < names_out.size(); ++i)
				{
					Assert::AreEqual(values_out[i], V.Val(names_out[i])/*,
						Tools::ToWString("i=" + to_string(i) + " name_out=" + names_out[i] + " values_out=" + values_out[i]).c_str()*/);
				}
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(SetValSubTree)
		{
			string test_file = "../FMTest/TestData/ValStoreLineT/SetValSubTree.txt";
			auto test_data = Tools::ReadTestData(test_file, 7);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				vector<string> names_in = STR::StrToVec(test_data[j][0], "#");
				vector<string> values_in = STR::StrToVec(test_data[j][1], "#");
				string name_cut = test_data[j][2];
				vector<string> names_in2= STR::StrToVec(test_data[j][3], "#");
				vector<string> values_in2 = STR::StrToVec(test_data[j][4], "#");
				vector<string> names_out = STR::StrToVec(test_data[j][5], "#");
				vector<string> values_out = STR::StrToVec(test_data[j][6], "#");

				Assert::AreEqual(names_in.size(), values_in.size(), Tools::ToWString("Error in file: sizes IN are different!").c_str());
				Assert::AreEqual(names_in2.size(), values_in2.size(), Tools::ToWString("Error in file: sizes IN2 are different!").c_str());
				Assert::AreEqual(names_out.size(), values_out.size(), Tools::ToWString("Error in file: sizes OUT are different!").c_str());

				ValStoreLineT<string> V;
				ValStoreLineT<string> V2;
				for (unsigned i = 0; i < names_in.size(); ++i) V.SetVal(names_in[i], values_in[i]);
				for (unsigned i = 0; i < names_in2.size(); ++i) V2.SetVal(names_in2[i], values_in2[i]);
				V.SetValSubTree(name_cut, V2);
				for (unsigned i = 0; i < names_out.size(); ++i)
				{
					Assert::AreEqual(values_out[i], V.Val(names_out[i])/*,
																														 Tools::ToWString("i=" + to_string(i) + " name_out=" + names_out[i] + " values_out=" + values_out[i]).c_str()*/);
				}
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
	};
}