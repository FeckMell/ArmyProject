#include "stdafx.h"
#include "Tools.h"
#include "CommonTypes\Except.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
wstring Tools::ToWString(string s_)
{
	wchar_t* wcs = new wchar_t[s_.length()];
	try{ mbstowcs(wcs, s_.c_str(), s_.length()); }
	catch (...){ return L"FUCKTOOLS"; }
	wstring result(wcs);

	delete[] wcs;
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<vector<string>> Tools::ReadTestData(string path_, unsigned size_)
{
	ifstream file;
	string file_line = "";
	vector<vector<string>> result;
	vector<string> data;

	file.open(path_);
	Assert::IsTrue(file.is_open(), ToWString("File:" + path_ + " not found").c_str());

	while (getline(file, file_line))
	{
		if (file_line.substr(0, 1) == "*") data.push_back(file_line.substr(1, string::npos));
		if (data.size() == size_)
		{
			result.push_back(data);
			data.clear();
		}
	}
	file.close();
	Assert::IsTrue(data.empty(), ToWString("File with test data is not correct. File:" + path_).c_str());
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void Tools::RecurCall(unsigned i_, boost::function<unsigned(unsigned)> f_i_change, boost::function<bool(unsigned)> f_if,
	boost::function<void(unsigned)> f_true, boost::function<void(unsigned, boost::any)> f_catch)
{
	try
	{
		if (f_if(i_)) f_true(i_);
		else RecurCall(f_i_change(i_), f_i_change, f_if, f_true, f_catch);
	}
	catch (Except e)
	{
		f_catch(i_, e);
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
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------