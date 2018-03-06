#include "stdafx.h"
#include "Operation.h"

using namespace std;

Operation* Operation::Get(std::string symbol_, bool delete_)
{
	static map<string, Operation*> thatOperation; //all operations saved here
	if ( delete_ ) // free memmory
	{
		for ( auto& e : thatOperation ) delete e.second;
		thatOperation.clear();
	}
	if ( thatOperation.empty() )//if  operation class has not been inited
	{
		thatOperation = map<string, Operation*>( 
		{ 
			{ "==", new Operation("==") }, { "!=", new Operation("!=") }, { ">=", new Operation(">=") }, 
			{ "<=", new Operation("<=") }, { ">",  new Operation(">") },  { "<",  new Operation("<") }, 
			{ "&&", new Operation("&&") }, { "||", new Operation("||") }, { "contains", new Operation("contains") },
			{ "!",  new Operation("!") },  { "(",  new Operation("(") },  { ")",  new Operation(")") },
			{ "^^", new Operation("^^") }
		}
		);
	}
	auto it = thatOperation.find(symbol_);
	if ( it != thatOperation.end() ) return it->second;
	else throw Except("Operation::Get unknown operation");
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
Operation::Operation(std::string symbol_) : thatSymbol(symbol_)
{
	if ( symbol_ == "==" )
	{
		thatPriority = 3;
		thatParAmount = 2;
		thatId = EQ;
	}
	else if ( symbol_ == "!=" )
	{
		thatPriority = 3;
		thatParAmount = 2;
		thatId = NEQ;
	}
	else if ( symbol_ == ">=" )
	{
		thatPriority = 3;
		thatParAmount = 2;
		thatId = GE;
	}
	else if ( symbol_ == "<=" )
	{
		thatPriority = 3;
		thatParAmount = 2;
		thatId = LE;
	}
	else if ( symbol_ == ">" )
	{
		thatPriority = 3;
		thatParAmount = 2;
		thatId = G;
	}
	else if ( symbol_ == "<" )
	{
		thatPriority = 3;
		thatParAmount = 2;
		thatId = L;
	}
	else if ( symbol_ == "&&" )
	{
		thatPriority = 2;
		thatParAmount = 2;
		thatId = AND;
	}
	else if ( symbol_ == "||" )
	{
		thatPriority = 2;
		thatParAmount = 2;
		thatId = OR;
	}
	else if ( symbol_ == "^^" )
	{
		thatPriority = 2;
		thatParAmount = 2;
		thatId = NEQ;
	}
	else if ( symbol_ == "!" )
	{
		thatPriority = 4;
		thatParAmount = 1;
		thatId = NOT;
	}
	/*else if ( symbol_ == "in" )
	{
		thatPriority = 3;
		thatBinary = true;
	}*/
	else if ( symbol_ == "contains" )
	{
		thatPriority = 3;
		thatParAmount = 2;
		thatId = CONTAINS;
	}
	else if ( symbol_ == "(" )
	{
		thatPriority = 1;
		thatParAmount = 0;
		thatId = BROP;
	}
	else if ( symbol_ == ")" )
	{
		thatPriority = 1;
		thatParAmount = 0;
		thatId = BRCL;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
/* EQUAL */
//*///------------------------------------------------------------------------------------------
bool Operation::EQ::Use(const string& x, const int& y) { return x == std::to_string(y); }
bool Operation::EQ::Use(const string& x, const bool& y) { return STR::ToBool(x) == y; }
bool Operation::EQ::Use(const string& x, const string& y) { return x == y; }
bool Operation::EQ::Use(const bool& x, const int& y) { return x == bool(y); }
bool Operation::EQ::Use(const bool& x, const bool& y) { return x == y; }
bool Operation::EQ::Use(const bool& x, const string& y) { return x == STR::ToBool(y); }
bool Operation::EQ::Use(const int& x, const int& y) { return x == y; }
bool Operation::EQ::Use(const int& x, const bool& y) { return bool(x) == y; }
bool Operation::EQ::Use(const int& x, const string& y) { return to_string(x) == y; }
//*///------------------------------------------------------------------------------------------
/* NOT EQUAL */
//*///------------------------------------------------------------------------------------------
bool Operation::NEQ::Use(const string& x, const int& y) { return x != std::to_string(y); }
bool Operation::NEQ::Use(const string& x, const bool& y) { return STR::ToBool(x) != y; }
bool Operation::NEQ::Use(const string& x, const string& y) { return x != y; }
bool Operation::NEQ::Use(const bool& x, const int& y) { return x != bool(y); }
bool Operation::NEQ::Use(const bool& x, const bool& y) { return x != y; }
bool Operation::NEQ::Use(const bool& x, const string& y) { return x != STR::ToBool(y); }
bool Operation::NEQ::Use(const int& x, const int& y) { return x != y; }
bool Operation::NEQ::Use(const int& x, const bool& y) { return bool(x) != y; }
bool Operation::NEQ::Use(const int& x, const string& y) { return to_string(x) != y; }
//*///------------------------------------------------------------------------------------------
/* GREATER OR EQUAL */
//*///------------------------------------------------------------------------------------------
bool Operation::GE::Use(const string& x, const int& y) { return STR::ToInt(x) >= y; }
bool Operation::GE::Use(const string& x, const bool& y) { return STR::ToBool(x) >= y; }
bool Operation::GE::Use(const string& x, const string& y) { return STR::ToInt(x) >= STR::ToInt(y); }
bool Operation::GE::Use(const bool& x, const int& y) { return x >= bool(y); }
bool Operation::GE::Use(const bool& x, const bool& y) { return x >= y; }
bool Operation::GE::Use(const bool& x, const string& y) { return x >= STR::ToBool(y); }
bool Operation::GE::Use(const int& x, const int& y) { return x >= y; }
bool Operation::GE::Use(const int& x, const bool& y) { return bool(x) >= y; }
bool Operation::GE::Use(const int& x, const string& y) { return x >= STR::ToInt(y); }
//*///------------------------------------------------------------------------------------------
/* LESS OR EQUAL */
//*///------------------------------------------------------------------------------------------
bool Operation::LE::Use(const string& x, const int& y)  { return STR::ToInt(x) <= y; }
bool Operation::LE::Use(const string& x, const bool& y) { return STR::ToBool(x) <= y; }
bool Operation::LE::Use(const string& x, const string& y)     { return STR::ToInt(x) <= STR::ToInt(y); }
bool Operation::LE::Use(const bool& x, const int& y)    { return x <= bool(y); }
bool Operation::LE::Use(const bool& x, const bool& y)   { return x <= y; }
bool Operation::LE::Use(const bool& x, const string& y) { return x <= STR::ToBool(y); }
bool Operation::LE::Use(const int& x, const int& y)     { return x <= y; }
bool Operation::LE::Use(const int& x, const bool& y) { return bool(x) <= y; }
bool Operation::LE::Use(const int& x, const string& y)  { return x <= STR::ToInt(y); }
//*///------------------------------------------------------------------------------------------
/* GREATER */
//*///------------------------------------------------------------------------------------------
bool Operation::G::Use(const string& x, const int& y) { return STR::ToInt(x) > y; }
bool Operation::G::Use(const string& x, const bool& y) { return STR::ToBool(x) > y; }
bool Operation::G::Use(const string& x, const string& y) { return STR::ToInt(x) > STR::ToInt(y); }
bool Operation::G::Use(const bool& x, const int& y) { return x > bool(y); }
bool Operation::G::Use(const bool& x, const bool& y) { return x > y; }
bool Operation::G::Use(const bool& x, const string& y) { return x > STR::ToBool(y); }
bool Operation::G::Use(const int& x, const int& y) { return x > y; }
bool Operation::G::Use(const int& x, const bool& y) { return bool(x) > y; }
bool Operation::G::Use(const int& x, const string& y) { return x > STR::ToInt(y); }
//*///------------------------------------------------------------------------------------------
/* LESS */
//*///------------------------------------------------------------------------------------------
bool Operation::L::Use(const string& x, const int& y) { return STR::ToInt(x) < y; }
bool Operation::L::Use(const string& x, const bool& y) { return STR::ToBool(x) < y; }
bool Operation::L::Use(const string& x, const string& y) { return STR::ToInt(x) < STR::ToInt(y); }
bool Operation::L::Use(const bool& x, const int& y) { return x < bool(y); }
bool Operation::L::Use(const bool& x, const bool& y) { return x < y; }
bool Operation::L::Use(const bool& x, const string& y) { return x < STR::ToBool(y); }
bool Operation::L::Use(const int& x, const int& y) { return x < y; }
bool Operation::L::Use(const int& x, const bool& y) { return bool(x) < y; }
bool Operation::L::Use(const int& x, const string& y) { return x < STR::ToInt(y); }
//*///------------------------------------------------------------------------------------------
/* AND */
//*///------------------------------------------------------------------------------------------
bool Operation::AND::Use(const string& x, const int& y) { return STR::ToInt(x) && y; }
bool Operation::AND::Use(const string& x, const bool& y) { return STR::ToBool(x) && y; }
bool Operation::AND::Use(const string& x, const string& y) { return STR::ToInt(x) && STR::ToInt(y); }
bool Operation::AND::Use(const bool& x, const int& y) { return x && bool(y); }
bool Operation::AND::Use(const bool& x, const bool& y) { return x && y; }
bool Operation::AND::Use(const bool& x, const string& y) { return x && STR::ToBool(y); }
bool Operation::AND::Use(const int& x, const int& y) { return x && y; }
bool Operation::AND::Use(const int& x, const bool& y) { return bool(x) && y; }
bool Operation::AND::Use(const int& x, const string& y) { return x && STR::ToInt(y); }
//*///------------------------------------------------------------------------------------------
/* OR */
//*///------------------------------------------------------------------------------------------
bool Operation::OR::Use(const string& x, const int& y) { return STR::ToInt(x) || y; }
bool Operation::OR::Use(const string& x, const bool& y) { return STR::ToBool(x) || y; }
bool Operation::OR::Use(const string& x, const string& y) { return STR::ToInt(x) || STR::ToInt(y); }
bool Operation::OR::Use(const bool& x, const int& y) { return x || y; }
bool Operation::OR::Use(const bool& x, const bool& y) { return x || y; }
bool Operation::OR::Use(const bool& x, const string& y) { return x || STR::ToBool(y); }
bool Operation::OR::Use(const int& x, const int& y) { return x || y; }
bool Operation::OR::Use(const int& x, const bool& y) { return x || y; }
bool Operation::OR::Use(const int& x, const string& y) { return x || STR::ToInt(y); }
//*///------------------------------------------------------------------------------------------
/* CONTAINS */
//*///------------------------------------------------------------------------------------------
bool Operation::CONTAINS::Use(const string& x, const int& y) { return x.find(to_string(y)) != string::npos; }
bool Operation::CONTAINS::Use(const string& x, const string& y) { return x.find(y) != string::npos; }
bool Operation::CONTAINS::Use(const int& x, const int& y) { return to_string(x).find(to_string(y)) != string::npos; }
bool Operation::CONTAINS::Use(const int& x, const string& y) { return to_string(x).find(y) != string::npos; }
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
