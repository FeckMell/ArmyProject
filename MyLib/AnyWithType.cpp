#include "stdafx.h"
#include "AnyWithType.h"

using namespace std;
std::map<std::string, unsigned> AnyWithType::FromStrToUns = {
	{ "NONE", AnyWithType::NONE },
	{ "BOOL", AnyWithType::BOOL },
	{ "INT", AnyWithType::INT },
	{ "STRING", AnyWithType::STRING },
	{ "none", AnyWithType::NONE },
	{ "bool", AnyWithType::BOOL },
	{ "int", AnyWithType::INT },
	{ "string", AnyWithType::STRING },
	{ "None", AnyWithType::NONE },
	{ "Bool", AnyWithType::BOOL },
	{ "Int", AnyWithType::INT },
	{ "String", AnyWithType::STRING }
};
std::map<unsigned, std::string> AnyWithType::FromUnsToStr = {
	{ AnyWithType::NONE, "NONE" },
	{ AnyWithType::BOOL, "BOOL" },
	{ AnyWithType::INT, "INT" },
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
	thatDataTypeS = FromUnsToStr[type_];
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------