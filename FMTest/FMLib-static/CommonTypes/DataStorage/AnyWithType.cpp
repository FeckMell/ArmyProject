#include "stdafx.h"
#include "AnyWithType.h"

using namespace std;
map<string, unsigned> AnyWithType::FromStrToUns = {
	{ "NONE", AnyWithType::NONE },
	{ "none", AnyWithType::NONE },
	{ "None", AnyWithType::NONE },
	{ "BOOL", AnyWithType::BOOL },
	{ "bool", AnyWithType::BOOL },
	{ "Bool", AnyWithType::BOOL },
	{ "INT", AnyWithType::INT },
	{ "int", AnyWithType::INT },
	{ "Int", AnyWithType::INT },
	{ "DOUBLE", AnyWithType::DOUBLE },
	{ "double", AnyWithType::DOUBLE },
	{ "Double", AnyWithType::DOUBLE },
	{ "UNSIGNED", AnyWithType::UNSIGNED },
	{ "unsigned", AnyWithType::UNSIGNED },
	{ "Unsigned", AnyWithType::UNSIGNED },
	{ "STRING", AnyWithType::STRING },
	{ "string", AnyWithType::STRING },
	{ "String", AnyWithType::STRING },
	{ "OTHER", AnyWithType::OTHER },
	{ "other", AnyWithType::OTHER },
	{ "Other", AnyWithType::OTHER }
};
map<unsigned, string> AnyWithType::FromUnsToStr = {
	{ AnyWithType::NONE, "NONE" },
	{ AnyWithType::BOOL, "BOOL" },
	{ AnyWithType::INT, "INT" },
	{ AnyWithType::DOUBLE, "DOUBLE" },
	{ AnyWithType::UNSIGNED, "UNSIGNED" },
	{ AnyWithType::STRING, "STRING" },
	{ AnyWithType::OTHER, "OTHER" }
};
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
AnyWithType::AnyWithType(boost::any data_, string type_) :thatData(data_), thatDataTypeS(type_)
{
	thatDataTypeU = FromStrToUns[type_];
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
AnyWithType::AnyWithType(boost::any data_, unsigned type_) : thatData(data_), thatDataTypeU(type_)
{
	thatDataTypeS = FromUnsToStr[type_];
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
boost::any AnyWithType::Data()
{
	return thatData;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string AnyWithType::TypeS()
{
	return thatDataTypeS;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
unsigned AnyWithType::TypeU()
{
	return thatDataTypeU;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void AnyWithType::Set(boost::any data_, string type_)
{
	thatData = data_;
	thatDataTypeS = type_;

	auto it = FromStrToUns.find(type_);
	if ( it == FromStrToUns.end() ) thatDataTypeU = AnyWithType::OTHER;
	else thatDataTypeU = it->second;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void AnyWithType::Set(boost::any data_, unsigned type_)
{
	thatData = data_;
	thatDataTypeU = type_;
	auto it = FromUnsToStr.find(type_);
	if (it == FromUnsToStr.end()) thatDataTypeS = "OTHER";
	else thatDataTypeS = it->second;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------