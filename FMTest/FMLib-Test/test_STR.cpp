#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "Interfaces\Str.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace FMTest
{		
	TEST_CLASS(test_STR)
	{
	public:
		
		/*TEST_METHOD(SelfTest)
		{
			auto v = Tools::ReadTestData("../FMLib-Test/TestData/STR/StrInBetween.txt", 4);
		}			*/
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(StrBetween)
		{
			string test_file = "../FMLib-Test/TestData/STR/StrBetween.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (auto& e : test_data)
			{
				Assert::AreEqual(e[3], STR::StrBetween(e[0], e[1], e[2]),
					Tools::ToWString("Error in data:" + e[0] + " " + e[1] + " " + e[2]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(StrInBetween)
		{
			string test_file = "../FMLib-Test/TestData/STR/StrInBetween.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (auto& e : test_data)
			{
				Assert::AreEqual(e[3], STR::StrInBetween(e[0], e[1], e[2]),
					Tools::ToWString("Error in data:" + e[0] + " " + e[1] + " " + e[2]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(StrBetweenVec)
		{
			string test_file = "../FMLib-Test/TestData/STR/StrBetweenVec.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (auto& e : test_data)
			{
				vector<string> result = STR::StrBetweenVec(e[0], e[1], e[2]);
				string str_result = "";
				for (auto& e1 : result) str_result += e1 + " "; if(!str_result.empty())str_result.pop_back();
				Assert::AreEqual(e[3], str_result,
					Tools::ToWString("Error in data:" + e[0] + " " + e[1] + " " + e[2]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(StrInBetweenVec)
		{
			string test_file = "../FMLib-Test/TestData/STR/StrInBetweenVec.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (auto& e : test_data)
			{
				vector<string> result = STR::StrInBetweenVec(e[0], e[1], e[2]);
				string str_result = "";
				for (auto& e1 : result) str_result += e1 + " "; if (!str_result.empty())str_result.pop_back();
				Assert::AreEqual(e[3], str_result,
					Tools::ToWString("Error in data:" + e[0] + " " + e[1] + " " + e[2]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(Split)
		{
			string test_file = "../FMLib-Test/TestData/STR/Split.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (auto& e : test_data)
			{
				pair<string, string> result = STR::Split(e[0], e[1], false);
				string str_result = result.first + " " + result.second;
				Assert::AreEqual(e[2], str_result,
					Tools::ToWString("Error in data:" + e[0] + " " + e[1]).c_str());

				result = STR::Split(e[0], e[1], true);
				str_result = result.first + " " + result.second;
				Assert::AreEqual(e[3], str_result,
					Tools::ToWString("Error in data:" + e[0] + " " + e[1]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(ReplaceInStrOnce)
		{
			string test_file = "../FMLib-Test/TestData/STR/ReplaceInStrOnce.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (auto& e : test_data)
			{
				Assert::AreEqual(e[3], STR::ReplaceInStrOnce(e[0], e[1], e[2]),
					Tools::ToWString("Error in data:" + e[0] + " " + e[1] + " " + e[2]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(ReplaceInStrAll)
		{
			string test_file = "../FMLib-Test/TestData/STR/ReplaceInStrAll.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (auto& e : test_data)
			{
				Assert::AreEqual(e[3], STR::ReplaceInStrAll(e[0], e[1], e[2]),
					Tools::ToWString("Error in data:" + e[0] + " " + e[1] + " " + e[2]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(FindInStrAll)
		{
			string test_file = "../FMLib-Test/TestData/STR/FindInStrAll.txt";
			auto test_data = Tools::ReadTestData(test_file, 3);
			for (auto& e : test_data)
			{
				vector<unsigned> result = STR::FindInStrAll(e[0], e[1]);
				string str_result = "";
				for (auto& e1 : result) str_result += to_string(e1) + " "; if (!str_result.empty())str_result.pop_back();
				Assert::AreEqual(e[2], str_result,
					Tools::ToWString("Error in data:" + e[0] + " " + e[1]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------ ToLowerCase
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(ToLowerCase)
		{
			string test_file = "../FMLib-Test/TestData/STR/ToLowerCase.txt";
			auto test_data = Tools::ReadTestData(test_file, 2);
			for (auto& e : test_data)
			{
				Assert::AreEqual(e[1], STR::ToLowerCase(e[0]));
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(ToUpperCase)
		{
			string test_file = "../FMLib-Test/TestData/STR/ToUpperCase.txt";
			auto test_data = Tools::ReadTestData(test_file, 2);
			for (auto& e : test_data)
			{
				Assert::AreEqual(e[1], STR::ToUpperCase(e[0]));
			}
		}
		//*///------------------------------------------------------------------------------------------ GenMultTimes
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(GenMultTimes)
		{
			string test_file = "../FMLib-Test/TestData/STR/GenMultTimes.txt";
			auto test_data = Tools::ReadTestData(test_file, 3);
			for (auto& e : test_data)
			{
				Assert::AreEqual(e[2], STR::GenMultTimes(e[0], stoi(e[1])),
					Tools::ToWString("Error in data:" + e[0] + " " + e[1]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------SubStrFromTo
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(SubStrFromTo)
		{
			string test_file = "../FMLib-Test/TestData/STR/SubStrFromTo.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (auto& e : test_data)
			{
				Assert::AreEqual(e[3], STR::SubStrFromTo(e[0], stoi(e[1]), stoi(e[2])),
					Tools::ToWString("Error in data:" + e[0] + " " + e[1] + " " + e[2]).c_str());
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
	};
}