#include "stdafx.h"
#include "Evulation2.h"

using namespace std;

//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
/* EQUAL */
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool Evulation2::EQ::eq(const string& x, const int& y)
{
	return x == std::to_string(y);
}
bool Evulation2::EQ::eq(const string& x, const bool& y)
{
	return STR::ToBool(x) == y;
}
bool Evulation2::EQ::eq(const string& x, string& y)
{
	return x == y;
}
bool Evulation2::EQ::eq(const bool& x, const int& y)
{
	return x == y;
}
bool Evulation2::EQ::eq(const bool& x, const bool& y)
{
	return x == y;
}
bool Evulation2::EQ::eq(const bool& x, const string& y)
{
	return x == STR::ToBool(y);
}
bool Evulation2::EQ::eq(const int& x, const int& y)
{
	return x == y;
}
bool Evulation2::EQ::eq(const int& x, const bool& y)
{
	return x == y;
}
bool Evulation2::EQ::eq(const int& x, const string& y)
{
	return to_string(x) == y;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
/* NOT EQUAL */
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool Evulation2::NEQ::neq(const string& x, const int& y)
{
	return x != std::to_string(y);
}
bool Evulation2::NEQ::neq(const string& x, const bool& y)
{
	return STR::ToBool(x) != y;
}
bool Evulation2::NEQ::neq(const string& x, string& y)
{
	return x != y;
}
bool Evulation2::NEQ::neq(const bool& x, const int& y)
{
	return x != y;
}
bool Evulation2::NEQ::neq(const bool& x, const bool& y)
{
	return x != y;
}
bool Evulation2::NEQ::neq(const bool& x, const string& y)
{
	return x != STR::ToBool(y);
}
bool Evulation2::NEQ::neq(const int& x, const int& y)
{
	return x != y;
}
bool Evulation2::NEQ::neq(const int& x, const bool& y)
{
	return x != y;
}
bool Evulation2::NEQ::neq(const int& x, const string& y)
{
	return to_string(x) != y;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------