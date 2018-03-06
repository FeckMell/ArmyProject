#include "stdafx.h"
#include "StringWithType.h"

using namespace std;
std::map<std::string, unsigned> StringWithType::FromStrToUns = { 
	{ "NONE", StringWithType::NONE },
	{ "BOOL", StringWithType::BOOL },
	{ "INT", StringWithType::INT },
	{ "STRING", StringWithType::STRING },
	{ "none", StringWithType::NONE },
	{ "bool", StringWithType::BOOL },
	{ "int", StringWithType::INT },
	{ "string", StringWithType::STRING },
	{ "None", StringWithType::NONE },
	{ "Bool", StringWithType::BOOL },
	{ "Int", StringWithType::INT },
	{ "String", StringWithType::STRING }
};
std::map<unsigned, std::string> StringWithType::FromUnsToStr={
	{ StringWithType::NONE ,"NONE"},
	{ StringWithType::BOOL, "BOOL" },
	{ StringWithType::INT, "INT" },
	{ StringWithType::STRING, "STRING" }
};
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
StringWithType::StringWithType(string data_, string type_) :thatData(data_), thatDataTypeS(type_)
{
	thatDataTypeU = FromStrToUns[type_];
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
StringWithType::StringWithType(string data_, unsigned type_) : thatData(data_), thatDataTypeU(type_)
{
	thatDataTypeS = FromUnsToStr[type_];
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string StringWithType::Data()
{
	return thatData;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string StringWithType::TypeS()
{
	return thatDataTypeS;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
unsigned StringWithType::TypeU()
{
	return thatDataTypeU;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void StringWithType::Set(string data_, string type_)
{
	thatData = data_;
	thatDataTypeS = type_;
	thatDataTypeU = FromStrToUns[type_];
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void StringWithType::Set(string data_, unsigned type_)
{
	thatData = data_;
	thatDataTypeU = type_;
	thatDataTypeS = FromUnsToStr[type_];
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------