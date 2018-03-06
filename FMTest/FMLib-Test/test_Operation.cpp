#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "Calculation\Math\Operation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FMTest
{
	TEST_CLASS(test_Operation)
	{
	public:

		/*
		static Operation* Get(std::string symbol_, bool delete_ = false);

		unsigned Id() { return thatId; }
		std::string Symbol() { return thatSymbol; }
		unsigned Priority() { return thatPriority; }
		unsigned ParAmount() { return thatParAmount; }
		*/
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(Get)
		{
			string test_file = "../FMLib-Test/TestData/Operation/Get.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				string oper = test_data[j][0];
				unsigned expect_prior = STR::ToUnsigned(test_data[j][1]);
				unsigned expect_pars = STR::ToUnsigned(test_data[j][2]);
				unsigned expect_id = STR::ToUnsigned(test_data[j][3]);

				auto result = Operation::Get(oper);

				Assert::AreEqual(oper, result->Symbol(),
					Tools::ToWString("Error in data symbol: " +to_string(j)).c_str());
				Assert::AreEqual(expect_prior, result->Priority(),
					Tools::ToWString("Error in data priority: " + to_string(j)).c_str());
				Assert::AreEqual(expect_pars, result->ParAmount(),
					Tools::ToWString("Error in data pars: " + to_string(j)).c_str());
				Assert::AreEqual(expect_id, result->Id(),
					Tools::ToWString("Error in data id: " + to_string(j)).c_str());
			}
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
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
	};
}