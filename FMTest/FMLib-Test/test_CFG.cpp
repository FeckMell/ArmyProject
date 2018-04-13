#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "Interfaces\CFG.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FMTest
{
	TEST_CLASS(test_CFG)
	{
	public:

		/*
	std::string ToString();
	
	void SetValFromFile(std::string path_, std::string filename_ = "fm.cfg");
	void SetVal(std::string node_name_, std::map<std::string, std::string> data_);
	void SetVal(std::string node_name_, ValStoreLineT<std::string> data_);
	void SetVal(std::string name_, std::string value_);

	std::string Val(std::string name_);
	ValStoreLineT<std::string> ValSubTree(std::string name_);
		*/
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(CutPathFromName)
		{
			string test_file = "../FMLib-Test/TestData/CFG/CutPathFromName.txt";
			auto test_data = Tools::ReadTestData(test_file, 2);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				string path = test_data[j][0];
				pair<string, string> expected = STR::Split(test_data[j][1], "#", false);
				pair<string, string> result = CFG::CutPathFromName(path);

				Assert::AreEqual(expected.first, result.first,
					Tools::ToWString(string("\npath was:" + path + " \nexpected=" + expected.first + "\nresult="
					+ result.first)).c_str());
				Assert::AreEqual(expected.second, result.second,
					Tools::ToWString(string("\npath was:") + path + "\nexpected=" + expected.second + "\nresult="
					+ result.second).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(SetVal_MAP)
		{
			string test_file = "../FMLib-Test/TestData/CFG/SetVal_MAP.txt";
			auto test_data = Tools::ReadTestData(test_file, 5);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				string node_name = test_data[j][0];
				vector<string> names_in = STR::StrToVec(test_data[j][1], "#");
				vector<string> value_in = STR::StrToVec(test_data[j][2], "#");
				map<string, string> data;
				vector<string> expected_names = STR::StrToVec(test_data[j][3], "#");
				vector<string> expected_value = STR::StrToVec(test_data[j][4], "#");
				
				for (unsigned i = 0; i < names_in.size(); ++i) data[names_in[i]] = value_in[i];

				CFG::SetVal(node_name, data);

				for (unsigned i = 0; i < expected_names.size(); ++i)
				{
					Assert::AreEqual(expected_value[i], CFG::Val(expected_names[i])/*,
						Tools::ToWString(string("\nexpected name:" + expected_names[i] + " \nexpected val=" + expected_value[i] +
						"\nresult val=" + CFG::Val(expected_names[i]))).c_str()*/);
				}
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(SetVal_VALSTORELINE)
		{
			string test_file = "../FMLib-Test/TestData/CFG/SetVal_VALSTORELINE.txt";
			//auto test_data = Tools::ReadTestData(test_file, 2);
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(SetVal_STRING)
		{
			string test_file = "../FMLib-Test/TestData/CFG/SetVal_STRING.txt";
			//auto test_data = Tools::ReadTestData(test_file, 2);
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
	};
}