#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "CommonTypes\Except.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FMTest
{
	TEST_CLASS(test_Except)
	{
	public:

		/*TEST_METHOD(SelfTest)
		{
		auto v = Tools::ReadTestData("../FMLib-Test/TestData/STR/StrInBetween.txt", 4);
		}			*/
		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(Except_)
		{
			string test_file = "../FMLib-Test/TestData/Except/test1.txt";
			auto test_data = Tools::ReadTestData(test_file, 4);
			unsigned i = 0;
			//Finish read from file and check result 
			boost::function<unsigned(unsigned)> f1 = [](unsigned i_){return i_ + 1; };
			boost::function<bool(unsigned)> f2 = [test_data](unsigned i_) {return i_ == stoi(test_data[0][0]); };
			boost::function<void(unsigned)> f3 = [test_data](unsigned i_){throw Except(test_data[0][1] + " " + to_string(i_ + 1)); };
			boost::function<void(unsigned, boost::any)> f4 = [test_data](unsigned i_, boost::any e_)
				{
					Except e = boost::any_cast<Except>(e_); 
					e.Push(test_data[0][1] + " " + to_string(i_));
					throw e;
			};
			try
			{
				Tools::RecurCall(i, f1, f2, f3, f4);
			}
			catch (Except e_)
			{
				string result1 = "What():";
				string result2 = "Pop():";
				while (!e_.Empty())
				{
					result1 += e_.What();
					result2 += e_.Pop();
				}
				Assert::AreEqual(test_data[0][2], result1, Tools::ToWString("Error in What(): data:" + test_data[0][1] + test_data[0][0]).c_str());
				Assert::AreEqual(test_data[0][2], result1, Tools::ToWString("Error in Pop(): data:" + test_data[0][1] + test_data[0][0]).c_str());
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
	};
}