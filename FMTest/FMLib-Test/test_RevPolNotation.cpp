#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "Calculation\Math\RevPolNotation.h"

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

				auto expr_new = rpn.GetExpressionSTR();
				auto expr_rpn = rpn.GetExpressionRPN();

				string result;

				while (!expr_rpn.empty())
				{
					if (expr_rpn.front().TypeS() == "Operation")
					{
						result += boost::any_cast<Operation*>(expr_rpn.front().Data())->Symbol() + " ";
					}
					else if (expr_rpn.front().TypeS() == "Name")
					{
						result += boost::any_cast<string>(expr_rpn.front().Data()) + " ";
					}
					else if (expr_rpn.front().TypeS() == "Value")
					{
						result += boost::any_cast<string>(expr_rpn.front().Data()) + " ";
					}
					else Assert::IsFalse(true);
					expr_rpn.pop_front();
				}
				result.pop_back();

				Assert::AreEqual(expected, result);	
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