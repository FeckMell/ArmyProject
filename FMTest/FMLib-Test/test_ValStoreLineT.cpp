#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "CommonTypes\DataStorage\ValStoreLineT.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FMTest
{
	TEST_CLASS(test_ValStoreLineT)
	{
	public:

		/*TEST_METHOD(SelfTest)
		{
		auto v = Tools::ReadTestData("../FMLib-Test/TestData/STR/StrInBetween.txt", 4);
		}			*/
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(Constructor)
		{
			string test_file = "../FMLib-Test/TestData/ValStoreLineT/Constructor.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(SetVal)
		{
			string test_file = "../FMLib-Test/TestData/ValStoreLineT/SetVal.txt";
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
			string test_file = "../FMLib-Test/TestData/ValStoreLineT/DelVal.txt";
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
			string test_file = "../FMLib-Test/TestData/ValStoreLineT/ValSubTree.txt";
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
			string test_file = "../FMLib-Test/TestData/ValStoreLineT/DelValSubTree.txt";
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
		TEST_METHOD(SetValSubTree_Store)
		{
			string test_file = "../FMLib-Test/TestData/ValStoreLineT/SetValSubTree.txt";
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
		TEST_METHOD(NodesNamesAll)
		{
			string test_file = "../FMLib-Test/TestData/ValStoreLineT/NodesNamesAll.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				vector<string> names_in = STR::StrToVec(test_data[j][0], "#");
				vector<string> values_in = STR::StrToVec(test_data[j][1], "#");
				string name_cut = test_data[j][2];
				vector<string> names_out = STR::StrToVec(test_data[j][3], "#");

				Assert::AreEqual(names_in.size(), values_in.size(), Tools::ToWString("Error in file: sizes IN are different!").c_str());
			
				ValStoreLineT<string> V;
				for (unsigned i = 0; i < names_in.size(); ++i) V.SetVal(names_in[i], values_in[i]);
				auto result = V.NodesNamesAll(name_cut);

				Assert::AreEqual(result.size(), names_out.size(),
					Tools::ToWString("Sizes of result and expected are different.").c_str());

				vector<string> res;
				size_t sz;
				while (!result.empty())
				{
					sz = result.size();
					for (unsigned i = 0; i < names_out.size(); ++i)
					{
						if (result.back() == names_out[i])
						{
							result.pop_back();
							break;
						}
					}
					if (sz == result.size())
					{
						res.push_back(result.back());
						result.pop_back();
					}
				}	
				;
				Assert::AreEqual(0, int(res.size()));
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(NodesNamesChild)
		{
			string test_file = "../FMLib-Test/TestData/ValStoreLineT/NodesNamesChild.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				vector<string> names_in = STR::StrToVec(test_data[j][0], "#");
				vector<string> values_in = STR::StrToVec(test_data[j][1], "#");
				string name_cut = test_data[j][2];
				vector<string> names_out = STR::StrToVec(test_data[j][3], "#");

				Assert::AreEqual(names_in.size(), values_in.size(), Tools::ToWString("Error in file: sizes IN are different!").c_str());

				ValStoreLineT<string> V;
				for (unsigned i = 0; i < names_in.size(); ++i) V.SetVal(names_in[i], values_in[i]);
				auto result = V.NodesNamesChild(name_cut);

				Assert::AreEqual(result.size(), names_out.size(),
					Tools::ToWString("Sizes of result and expected are different.").c_str());

				vector<string> res;
				size_t sz;
				while (!result.empty())
				{
					sz = result.size();
					for (unsigned i = 0; i < names_out.size(); ++i)
					{
						if (result.back() == names_out[i])
						{
							result.pop_back();
							break;
						}
					}
					if (sz == result.size())
					{
						res.push_back(result.back());
						result.pop_back();
					}
				}
				;
				Assert::AreEqual(0, int(res.size()));
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//TEST_METHOD(IsFinal)
		//TEST_METHOD(SetValSubTree_Map);
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
	};
}