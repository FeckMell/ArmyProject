#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "Calculation\Math\RevPolNotation.h"
#include "Parsers\Other\Army.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FMTest
{
	TEST_CLASS(test_RevPolNotation)
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
		TEST_METHOD(Constructor)
		{
			string test_file = "../FMLib-Test/TestData/RevPolNotation/Constructor.txt";
			auto test_data = Tools::ReadTestData(test_file, 2);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				string expr = test_data[j][0];
				string expected = test_data[j][1];
				
				RevPolNotation rpn(expr);
				string result = rpn.ToString();

				Assert::AreEqual(expected, result);	
			}
		}
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(Evulate)
		{
			string test_file = "../FMLib-Test/TestData/RevPolNotation/Evulate.txt";
			auto test_data = Tools::ReadTestData(test_file, 3);
			for (unsigned j = 0; j < test_data.size(); ++j)
			{
				string expr = test_data[j][0];
				string mess = test_data[j][1];
				string expected = test_data[j][2];

				Army army(mess, "%");
				RevPolNotation rpn(expr);
				string rpn_str = rpn.ToString();
				AnyWithType result = rpn.Evulate(boost::bind(&Army::Get, army, _1));

				Assert::AreEqual(expected, to_string(boost::any_cast<bool>(result.Data())));
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
	};
}