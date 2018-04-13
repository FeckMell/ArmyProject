//#include "stdafx.h"
#include "Str.h"
using namespace std;

string STR::StrBetween(string target_, string begin_, string end_)
{
	if (begin_.empty() || end_.empty() || target_.empty()) return "";
	size_t fd_begin = target_.find(begin_);
	if (fd_begin == string::npos) return "";
	else
	{
		size_t begin_l = begin_.length();
		size_t fd_end = target_.find(end_, fd_begin + begin_l);
		if (fd_end == string::npos) return "";
		else
		{
			size_t end_l = end_.length();
			return target_.substr(fd_begin + begin_l, fd_end - (fd_begin + begin_l));
		}
	}
}
//*///-------------------------------------
void STR::StrBetween_M(string& target_, string& begin_, string& end_)
{
	if (begin_.empty() || end_.empty() || target_.empty()) return;
	size_t fd_begin = target_.find(begin_);
	if (fd_begin == string::npos) return;
	else
	{
		size_t begin_l = begin_.length();
		size_t fd_end = target_.find(end_, fd_begin + begin_l);
		if (fd_end == string::npos) return;
		else
		{
			size_t end_l = end_.length();
			target_ = target_.substr(fd_begin + begin_l, fd_end - (fd_begin + begin_l));
			return;
		}
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> STR::StrBetweenVec(string target_, string begin_, string end_)
{
	vector<string> result;
	if (begin_.empty() || end_.empty() || target_.empty()) return result;
	size_t fd_begin = target_.find(begin_);
	size_t fd_end;
	size_t begin_l = begin_.length();
	size_t end_l = end_.length();
	string tmp;

	while (fd_begin != string::npos)
	{
		fd_end = target_.find(end_, fd_begin + begin_l);
		if (fd_end == string::npos) return result;
		else
		{
			string tmp = target_.substr(fd_begin + begin_l, fd_end - (fd_begin + begin_l));
			if (!tmp.empty()) result.push_back(tmp);
			fd_begin = target_.find(begin_, fd_end/* + end_l*/);
		}
	}
	return result;
}
//*///-------------------------------------
vector<string> STR::StrBetweenVec_M(string& target_, string& begin_, string& end_)
{
	vector<string> result;
	if (begin_.empty() || end_.empty() || target_.empty()) return result;
	size_t fd_begin = target_.find(begin_);
	size_t fd_end;
	size_t begin_l = begin_.length();
	size_t end_l = end_.length();
	string tmp;

	while (fd_begin != string::npos)
	{
		fd_end = target_.find(end_, fd_begin + begin_l);
		if (fd_end == string::npos) return result;
		else
		{
			string tmp = target_.substr(fd_begin + begin_l, fd_end - (fd_begin + begin_l));
			if (!tmp.empty()) result.push_back(tmp);
			fd_begin = target_.find(begin_, fd_end/* + end_l*/);
		}
	}
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::StrInBetween(string target_, string begin_, string end_)
{
	string result = StrBetween(target_, begin_, end_);
	if (result.empty()) return "";
	else return begin_ + result + end_;
}
//*///-------------------------------------
void STR::StrInBetween_M(string& target_, string& begin_, string& end_)
{
	StrBetween_M(target_, begin_, end_);
	if (target_.empty()) return;
	else target_ = begin_ + target_ + end_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> STR::StrInBetweenVec(string target_, string begin_, string end_)
{
	vector<string> result = StrBetweenVec(target_, begin_, end_);
	for (auto& e : result) e = begin_ + e + end_;
	return result;
}
//*///-------------------------------------
vector<string> STR::StrInBetweenVec_M(string& target_, string& begin_, string& end_)
{
	vector<string> result = StrBetweenVec_M(target_, begin_, end_);
	for (auto& e : result) e = begin_ + e + end_;
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::ReplaceInStrOnce(string target_, string old_, string new_)
{
	if (target_.empty()) return "";
	if (old_.empty()) return "";

	size_t fd = target_.find(old_);
	if (fd == string::npos) return target_;
	else return target_.replace(fd, old_.length(), new_);
}
//*///-------------------------------------
void STR::ReplaceInStrOnce_M(string& target_, string& old_, string& new_)
{
	if (target_.empty()) return;
	if (old_.empty()) return;

	size_t fd = target_.find(old_);
	if (fd == string::npos) return;
	else
	{
		target_ = target_.replace(fd, old_.length(), new_);
		return;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::ReplaceInStrAll(string target_, string old_, string new_)
{
	if (old_.empty()) return "";
	size_t fd = target_.find(old_);
	while (fd != string::npos)
	{
		target_.replace(fd, old_.length(), new_);
		fd = target_.find(old_, fd/* + new_.length()*/);
	}
	return target_;
}
//*///-------------------------------------
void STR::ReplaceInStrAll_M(string& target_, string& old_, string& new_)
{
	if (old_.empty()) return;
	size_t fd = target_.find(old_);
	while (fd != string::npos)
	{
		target_.replace(fd, old_.length(), new_);
		fd = target_.find(old_, fd/* + new_.length()*/);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::SubStrFromTo(string target_, size_t from_, size_t to_)
{
	if (from_ >= target_.length()) return "";
	if (from_ >= to_) return "";
	if (to_>target_.length()) return 	target_.substr(from_);
	else return target_.substr(from_, to_ - from_);
}
//*///-------------------------------------
void STR::SubStrFromTo_M(string& target_, size_t& from_, size_t to_)
{
	if (from_ >= target_.length()) { target_.clear(); return; }
	if (from_ >= to_) { target_.clear(); return; }
	if (to_ > target_.length()) { target_ = target_.substr(from_); return; }
	else { target_ = target_.substr(from_, to_ - from_); return; }
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> STR::StrToVec(string target_, string delimeter_)
{
	vector<string> result;
	if (delimeter_.empty()) return result;
	if (target_.empty()) return result;
	size_t fd_p = 0;
	size_t fd_n = target_.find(delimeter_);
	size_t l = delimeter_.length();
	while (fd_n != string::npos)
	{
		result.push_back(SubStrFromTo(target_, fd_p, fd_n));
		fd_p = fd_n + l;
		fd_n = target_.find(delimeter_, fd_p);
	}
	result.push_back(SubStrFromTo(target_, fd_p, fd_n));//to the end of str
	return result;
}
//*///-------------------------------------
vector<string> STR::StrToVec_M(string& target_, string& delimeter_)
{
	vector<string> result;
	if (delimeter_.empty()) return result;
	if (target_.empty()) return result;
	size_t fd_p = 0;
	size_t fd_n = target_.find(delimeter_);
	size_t l = delimeter_.length();
	while (fd_n != string::npos)
	{
		result.push_back(SubStrFromTo(target_, fd_p, fd_n));
		fd_p = fd_n + l;
		fd_n = target_.find(delimeter_, fd_p);
	}
	result.push_back(SubStrFromTo(target_, fd_p, fd_n));//to the end of str
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::VecToStr(vector<string> target_)
{
	string result = "";
	for (auto& e : target_) result += e;
	return result;
}
//*///-------------------------------------
string STR::VecToStr_M(vector<string>& target_)
{
	string result = "";
	for (auto& e : target_) result += e;
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::VecToStrWithDel(vector<string> target_, string delimeter_, bool last_)
{
	if (target_.empty()) return "";
	if (delimeter_.empty()) return VecToStr(target_);

	string result = "";
	for (size_t i = 0; i < target_.size() - 1; ++i) result += target_[i] + delimeter_;
	if (last_) result += target_.back() + delimeter_;
	else result += target_.back();
	return result;
}
//*///-------------------------------------
string STR::VecToStrWithDel_M(vector<string>& target_, string& delimeter_, bool last_)
{
	if (target_.empty()) return "";
	if (delimeter_.empty()) return VecToStr_M(target_);

	string result = "";
	for (size_t i = 0; i < target_.size() - 1; ++i) result += target_[i] + delimeter_;
	if (last_) result += target_.back() + delimeter_;
	else result += target_.back();
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<size_t> STR::FindInStrAll(string target_, string what_)
{
	vector<size_t> result;
	if (what_.empty()) return result;
	size_t length = what_.length();
	size_t fd = target_.find(what_);
	while (fd != string::npos)
	{
		result.push_back(fd);
		fd = target_.find(what_, fd + 1);
	}
	return result;
}
//*///-------------------------------------
vector<size_t> STR::FindInStrAll_M(string& target_, string& what_)
{
	vector<size_t> result;
	if (what_.empty()) return result;
	size_t length = what_.length();
	size_t fd = target_.find(what_);
	while (fd != string::npos)
	{
		result.push_back(fd);
		fd = target_.find(what_, fd + 1);
	}
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::ToLowerCase(string target_)
{
	for (auto&e : target_) e = tolower(e);
	return target_;
}
//*///-------------------------------------
void STR::ToLowerCase_M(string& target_)
{
	for (auto&e : target_)	e = tolower(e);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::ToUpperCase(string target_)
{
	for (auto&e : target_) e = toupper(e);
	return target_;
}
//*///-------------------------------------
void STR::ToUpperCase_M(string& target_)
{
	for (auto&e : target_) e = toupper(e);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool STR::IsNumeric(string str_)
{
	if (str_.empty()) return false;
	for (auto& e : str_) if (!isdigit(e)) return false;

	return true;
}
//*///-------------------------------------
bool STR::IsNumeric_M(const string& str_)
{
	if (str_.empty()) return false;
	for (auto& e: str_) if (!isdigit(e)) return false;

	return true;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::DeleteMisc(string target_)
{
	target_ = ReplaceInStrAll(target_, "  ", " ");
	target_ = ReplaceInStrAll(target_, "\r", "");

	return target_;
}
//*///-------------------------------------
void STR::DeleteMisc_M(string& target_)
{
	ReplaceInStrAll_M(target_, string("  "), string(" "));
	ReplaceInStrAll_M(target_, string("\r"), string(""));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::GenMultTimes(string generator_, unsigned times_)
{
	if (generator_.empty()) return "";
	if (times_ == 0) return "";
	string result = "";
	for (unsigned i = 0; i < times_; ++i)
	{
		result += generator_;
	}

	return result;
}
//*///-------------------------------------
string STR::GenMultTimes_M(string& generator_, unsigned& times_)
{
	if (generator_.empty()) return "";
	if (times_ == 0) return "";
	string result = "";
	for (unsigned i = 0; i < times_; ++i) result += generator_;

	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
pair<string, string> STR::Split(string target_, string delimeter_, bool include_)
{
	if (target_.empty()) return{ "", "" };
	if (delimeter_.empty()) return{ target_, "" };

	auto fd = target_.find(delimeter_);
	if (fd == string::npos) return{ target_, "" };

	pair<string, string> result;
	if (include_)
	{
		result = { STR::SubStrFromTo(target_, 0, fd + delimeter_.length()), STR::SubStrFromTo(target_, fd + delimeter_.length(), string::npos) };
		return result;
	}
	else
	{
		result = { STR::SubStrFromTo(target_, 0, fd), STR::SubStrFromTo(target_, fd + delimeter_.length(), string::npos) };
		return result;
	}
}
//*///-------------------------------------
pair<string, string> STR::Split_M(string& target_, string& delimeter_, bool& include_)
{
	if (target_.empty()) return{ "", "" };
	if (delimeter_.empty()) return{ target_, "" };

	auto fd = target_.find(delimeter_);
	if (fd == string::npos) return{ target_, "" };

	pair<string, string> result;
	if (include_)
	{
		result = { STR::SubStrFromTo(target_, 0, fd + delimeter_.length()), STR::SubStrFromTo(target_, fd + delimeter_.length(), string::npos) };
		return result;
	}
	else
	{
		result ={ STR::SubStrFromTo(target_, 0, fd), STR::SubStrFromTo(target_, fd + delimeter_.length(), string::npos) };
		return result;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool STR::ToBool(string str_)
{
	if (str_ == "0") return false;
	else if (str_ == "1") return true;
	else if (ToLowerCase(str_) == "true") return true;
	else if (ToLowerCase(str_) == "false") return false;
	else throw Except("Not bool");
}
//*///-------------------------------------
bool STR::ToBool_M(const string& str_)
{
	if (str_ == "0") return false;
	else if (str_ == "1") return true;
	else if (ToLowerCase(str_) == "true") return true;
	else if (ToLowerCase(str_) == "false") return false;
	else throw Except("Not bool");
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
int STR::ToInt(string str_)
{
	try { return stoi(str_); }
	catch (...) { throw Except("Not int"); }
}
//*///-------------------------------------
int STR::ToInt_M(const string& str_)
{
	try { return stoi(str_); }
	catch (...) { throw Except("Not int"); }
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
unsigned STR::ToUnsigned(string str_)
{
	try { return stoul(str_); }
	catch (...) { throw Except("Not unsigned"); }
}
//*///-------------------------------------
unsigned STR::ToUnsigned_M(const string& str_)
{
	try { return stoul(str_); }
	catch (...) { throw Except("Not unsigned"); }
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
double STR::ToDouble(string str_)
{
	try { return stod(str_); }
	catch (...) { throw Except("Not double\nstr_=" + str_); }
}
//*///-------------------------------------
double STR::ToDouble_M(const string& str_)
{
	try { return stod(str_); }
	catch (...) { throw Except("Not double"); }
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
wstring STR::ToWString(string s_)
{
	wchar_t* wcs = new wchar_t[s_.length()];
	try{ mbstowcs(wcs, s_.c_str(), s_.length()); }
	catch (...){ return L""; }
	wstring result(wcs);

	delete[] wcs;
	return result;
}
//*///-------------------------------------
wstring STR::ToWString_M(const string& s_)
{
	wchar_t* wcs = new wchar_t[s_.length()];
	try{ mbstowcs(wcs, s_.c_str(), s_.length()); }
	catch (...){ return L""; }
	wstring result(wcs);

	delete[] wcs;
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::ToString(wstring s_)
{
	char* mbs = new char[s_.length()];
	try{ wcstombs(mbs, s_.c_str(), s_.length()); }
	catch (...){ return ""; }
	string result(mbs);

	delete[] mbs;
	return result;
}
//*///-------------------------------------
string STR::ToString_M(const wstring& s_)
{
	char* mbs = new char[s_.length()];
	try{ wcstombs(mbs, s_.c_str(), s_.length()); }
	catch (...){ return ""; }
	string result(mbs);

	delete[] mbs;
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------