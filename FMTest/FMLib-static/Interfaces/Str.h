#pragma once
#include "stdafx.h"
#include "CommonTypes\Except.h"

class STR
{
public:

	/*Return string between @begin_ and @end_ in @target_, excludes @par2 and @par3
	if @target, @begin_ or @end_ are empty strings return ""
	if @begin_ not found return ""
	if @end_ not found return ""*/
	static std::string StrBetween(std::string target_, std::string begin_, std::string end_);
	static void StrBetween_M(std::string& target_, std::string& begin_, std::string& end_);
	/*Return string between @begin_ and @end_ in @target_ includes @par2 and @par3
	calls inside STR::StrBetween
	if @target, @begin_ or @end_ are empty strings return ""
	if @begin_ not found return ""
	if @end_ not found return ""
	if STR::StrBetween returns "" return "" */
	static std::string StrInBetween(std::string target_, std::string begin_, std::string end_);
	static void StrInBetween_M(std::string& target_, std::string& begin_, std::string& end_);



	/*Return vector, consists of all strings between @begin_ and @end_ in @target_, excludes @par2 and @par3
	if @begin_ or @end_ are empty strings return empty vector
	if in iteration @end_ not found return vector without substring(@begin_, string::npos)*/
	static std::vector<std::string> StrBetweenVec(std::string target_, std::string begin_, std::string end_);
	static std::vector<std::string> StrBetweenVec_M(std::string& target_, std::string& begin_, std::string& end_);
	/*Return vector, consists of all strings between @begin_ and @end_ in @target_, includes @par2 and @par3
	if @begin_ or @end_ are empty strings return empty vector
	if in iteration @end_ not found return vector without substring(@begin_, string::npos)*/
	static std::vector<std::string> StrInBetweenVec(std::string target_, std::string begin_, std::string end_);
	static std::vector<std::string> StrInBetweenVec_M(std::string& target_, std::string& begin_, std::string& end_);
	/*Return pair<string,string> consists of substrings before and after @delimeter
	if @target empty strings return pair<"","">
	if @delimeter not found return pair<@target,"">
	if @include is true - return pair<(before + @delimeter), after>*/
	static std::pair<std::string, std::string> Split(std::string target_, std::string delimeter_, bool include_);
	static std::pair<std::string, std::string> Split_M(std::string& target_, std::string& delimeter_, bool& include_);


	/*Return string where first entry of @old_ is replaced by @new_ in @target_
	if @old_ is "" return ""
	if @old_ not found return @target_*/
	static std::string ReplaceInStrOnce(std::string target_, std::string old_, std::string new_);
	static void ReplaceInStrOnce_M(std::string& target_, std::string& old_, std::string& new_);
	/*Return string where all entry of @old_ is replaced by @new_ in @target_
	if @old_ is "" return ""
	if @old_ not found return @target_*/
	static std::string ReplaceInStrAll(std::string target_, std::string old_, std::string new_);
	static void ReplaceInStrAll_M(std::string& target_, std::string& old_, std::string& new_);



	/*Return vector consists of all start positions of @what_ in @target_
	if @what_ is "" return empty vector
	if @what_ not found return empty vector*/
	static std::vector<size_t> FindInStrAll(std::string target_, std::string what_);
	static std::vector<size_t> FindInStrAll_M(std::string& target_, std::string& what_);
	/*Return string with all chars in LOWER case*/
	static std::string ToLowerCase(std::string target_);
	static void ToLowerCase_M(std::string& target_);
	/*Return string with all chars in UPPER case*/
	static std::string ToUpperCase(std::string target_);
	static void ToUpperCase_M(std::string& target_);
	/*Return string where all (double spaces, \r, ) are removed*/
	static std::string DeleteMisc(std::string target_);
	static void DeleteMisc_M(std::string& target_);
	/*Return string of @generator_ repeated @times_ times
	if @generator_ is "" return ""
	if @times_ is 0 return ""*/
	static std::string GenMultTimes(std::string generator_, unsigned times_);
	static std::string GenMultTimes_M(std::string& generator_, unsigned& times_);



	/*Return string from position @from_ to position @to_
	if @from_ > @target_.length() return ""
	if @end_ > @target_.length return substr(@from, string::npos)*/
	static std::string SubStrFromTo(std::string target_, std::size_t from_, std::size_t to_ = std::string::npos);
	static void SubStrFromTo_M(std::string& target_, std::size_t& from_, std::size_t to_ = std::string::npos);



	/*Return vector consists of  @target_ splited by @delimeret_
	if @delimeter_ is "" return empty vector
	if @delimeter_ not found return vector with one element = @target_*/
	static std::vector<std::string> StrToVec(std::string target_, std::string delimeter_); 
	static std::vector<std::string> StrToVec_M(std::string& target_, std::string& delimeter_);
	/*Return string as union of @target_ elements
	if vector empty return ""*/
	static std::string VecToStr(std::vector<std::string> target_);
	static std::string VecToStr_M(std::vector<std::string>& target_);
	/*Return string as union of @target_ elements with @delimeter_
	if @target_ is empty vector return ""
	if @last_ = true return string with @delimeter_ at the end 
	if @delimeter_ is "" calls STR::VecToStr(...)*/
	static std::string VecToStrWithDel(std::vector<std::string> target_, std::string delimeter_, bool last_ = true);
	static std::string VecToStrWithDel_M(std::vector<std::string>& target_, std::string& delimeter_, bool last_ = true);

	/*Converts std::string to std::wstring */
	static std::wstring ToWString(std::string s_);
	static std::wstring ToWString_M(const std::string& s_);
	/*Converts std::wstring to std::string*/
	static std::string ToString(std::wstring s_);
	static std::string ToString_M(const std::wstring& s_);




	/*Return true if string is numeric, return false else*/
	static bool IsNumeric(std::string str_);
	static bool IsNumeric_M(const std::string& str_);
	/*Return bool if string is int, else throw Except*/
	static bool ToBool(std::string str_);
	static bool ToBool_M(const std::string& str_);
	/*Return int if string is int, else throw Except*/
	static int ToInt(std::string str_);
	static int ToInt_M(const std::string& str_);
	/*Return unsigned if string is int, else throw Except*/
	static unsigned ToUnsigned(std::string str_);
	static unsigned ToUnsigned_M(const std::string& str_);
	/*Return double if string is int, else throw Except*/
	static double ToDouble(std::string str_);
	static double ToDouble_M(const std::string& str_);


private:

	STR(){}
	~STR(){}

};