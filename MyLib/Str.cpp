#include "stdafx.h"
#include "Str.h"
using namespace std;

string STR::StrBetween(string target_, string begin_, string end_)
	{
	if ( begin_.empty() || end_.empty() ) return "";
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
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> STR::StrBetweenVec(string target_, string begin_, string end_)
	{
		vector<string> result;
		if ( begin_.empty() || end_.empty() ) return result;
		size_t fd_begin = target_.find(begin_);
		size_t fd_end;
		size_t begin_l = begin_.length();
		size_t end_l = end_.length();

		while (fd_begin != string::npos)
		{
			fd_end = target_.find(end_, fd_begin + begin_l);
			if (fd_end == string::npos) return result;
			else
			{
				result.push_back(target_.substr(fd_begin + begin_l, fd_end - (fd_begin + begin_l)));
				fd_begin = target_.find(begin_, fd_end + end_l);
			}
		}
		return result;
	}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::StrInBetween(string target_, string begin_, string end_)
	{
		string result = StrBetween(target_, begin_, end_);
		if ( result.empty() ) return "";
		else return begin_ + result + end_;
	}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> STR::StrInBetweenVec(string target_, string begin_, string end_)
	{
		vector<string> result = StrBetweenVec(target_, begin_, end_);
		for (auto& e : result) e = begin_ + e + end_;
		return result;
	}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::ReplaceInStrOnce(string target_, string old_, string new_)
	{
	if ( old_.empty()) return "";
		size_t fd = target_.find(old_);
		if (fd == string::npos) return target_;
		else return target_.replace(fd, old_.length(), new_);
	}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::ReplaceInStrAll(string target_, string old_, string new_)
	{
	if ( old_.empty() ) return "";
		size_t fd = target_.find(old_);
		while (fd != string::npos)
		{
			target_.replace(fd, old_.length(), new_);
			fd = target_.find(old_, fd + new_.length());
		}
		return target_;
	}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::SubStrFromTo(string target_, size_t from_, size_t to_)
	{
		if (from_ >= target_.length()) return "";
		else return target_.substr(from_, to_ - from_);
	}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> STR::StrToVec(string target_, string delimeter_)
	{
		vector<string> result;
		if ( delimeter_.empty() ) return result;
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
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::VecToStrWithDel(vector<string> target_, string delimeter_, bool last_)
{
	if ( target_.empty() ) return "";
	if ( delimeter_.empty() ) return VecToStr(target_);

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
	if ( what_.empty() ) return result;
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
	string result = "";
	for (size_t i = 0; i < target_.length(); ++i)
	{
		result += tolower(target_[i]);
	}
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::ToUpperCase(string target_)
{
	string result = "";
	for (size_t i = 0; i < target_.length(); ++i)
	{
		result += toupper(target_[i]);
	}
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool STR::IsNumeric(std::string str_)
{
	if ( str_.empty() ) return false;
	for (size_t i = 0; i < str_.size(); ++i) if (!isdigit(str_[i])) return false;
	return true;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::DeleteMisc(std::string target_)
{
	target_ = ReplaceInStrAll(target_, "  ", " ");
	target_ = ReplaceInStrAll(target_, "\r", "");
	return target_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string STR::GenMultTimes(string generator_, unsigned times_)
{
	if ( generator_.empty() ) return "";
	if ( times_ == 0 ) return "";
	string result = "";
	for ( unsigned i = 0; i < times_; ++i )
	{
		result += generator_;
	}
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
pair<string, string> STR::Split(string target_, string delimeter_, bool include_)
{
	if ( target_.empty() ) return {"",""};
	if ( delimeter_.empty() ) return { target_, "" };

	auto fd = target_.find(delimeter_);
	if ( fd == string::npos ) return { target_, "" };

	pair<string, string> result;
	if ( include_ )
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
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
/*Return bool if string is int, else throw Except*/
bool STR::ToBool(std::string str_)
{
	if ( str_ == "0" ) return false;
	else if ( str_ == "1" ) return true;
	else if ( ToLowerCase(str_) == "true" ) return true;
	else if ( ToLowerCase(str_) == "false" ) return false;
	else throw Except("Not bool\nstr_=" + str_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
int STR::ToInt(std::string str_)
{
	try { return stoi(str_); }
	catch ( ... ) { throw Except("Not int\nstr_=" + str_); }
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
unsigned STR::ToUnsigned(std::string str_)
{
	try { return stoul(str_); }
	catch ( ... ) { throw Except("Not unsigned\nstr_=" + str_); }
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
double STR::ToDouble(std::string str_)
{
	try { return stod(str_); }
	catch ( ... ) { throw Except("Not double\nstr_=" + str_); }
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------