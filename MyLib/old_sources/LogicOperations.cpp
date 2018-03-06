#include "stdafx.h"
#include "LogicOperations.h"

typedef LogicOperations LO;

LO::LogicOperations(string symbol_) :thatSymbol(symbol_)
{
	if ( symbol_ == "==" )
	{
		thatPriority = 3;
		thatBinary = true;
		//thatf_ds = &Evulation::Op_EQ;
		//thatf_di = &Evulation::Op_EQ;
		//thatf_db = &Evulation::Op_EQ;
	}
	else if ( symbol_ == "!=" )
	{
		thatPriority = 3;
		thatBinary = true;
		thatf_ds = &LO::Oper_NEQ;
		thatf_di = &LO::Oper_NEQ;
		thatf_db = &LO::Oper_NEQ;
	}
	else if ( symbol_ == ">=" )
	{
		thatPriority = 3;
		thatBinary = true;
		thatf_ds = &LO::Oper_GE;
		thatf_di = &LO::Oper_GE;
		thatf_db = &LO::Oper_GE;
	}
	else if ( symbol_ == "<=" )
	{
		thatPriority = 3;
		thatBinary = true;
		thatf_ds = &LO::Oper_LE;
		thatf_di = &LO::Oper_LE;
		thatf_db = &LO::Oper_LE;
	}
	else if ( symbol_ == ">" )
	{
		thatPriority = 3;
		thatBinary = true;
		thatf_ds = &LO::Oper_G;
		thatf_di = &LO::Oper_G;
		thatf_db = &LO::Oper_G;
	}
	else if ( symbol_ == "<" )
	{
		thatPriority = 3;
		thatBinary = true;
		thatf_ds = &LO::Oper_L;
		thatf_di = &LO::Oper_L;
		thatf_db = &LO::Oper_L;
	}
	else if ( symbol_ == "&&" )
	{
		thatPriority = 2;
		thatBinary = true;
		thatf_db = &LO::Oper_AND;
	}
	else if ( symbol_ == "||" )
	{
		thatPriority = 2;
		thatBinary = true;
		thatf_db = &LO::Oper_OR;
	}
	else if ( symbol_ == "^^" )
	{
		thatPriority = 2;
		thatBinary = true;
		thatf_db = &LO::Oper_XOR;
	}
	else if ( symbol_ == "!" )
	{
		thatPriority = 4;
		thatBinary = false;
		thatf_ub = &LO::Oper_NOT;
	}
	else if ( symbol_ == "in" )
	{
		thatPriority = 3;
		thatBinary = true;
	}
	else if ( symbol_ == "contains" )
	{
		thatPriority = 3;
		thatBinary = true;
		thatf_ds = &LO::Oper_CONTAINS;
	}
	else if ( symbol_ == "(" )
	{
		thatPriority = 1;
		thatBinary = false;
		thatf_ub = &LO::Oper_fake; 
	}
	else if ( symbol_ == ")" )
	{
		thatPriority = 1;
		thatBinary = false;
		thatf_ub = &LO::Oper_fake;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Oper_EQ(string f_, string s_)
{
	return f_ == s_;
}
bool LO::Oper_EQ(int f_, int s_)
{
	return f_ == s_;
}
bool LO::Oper_EQ(bool f_, bool s_)
{
	return f_ == s_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Oper_NEQ(string f_, string s_)
{
	return f_ != s_;
}
bool LO::Oper_NEQ(int f_, int s_)
{
	return f_ != s_;
}
bool LO::Oper_NEQ(bool f_, bool s_)
{
	return f_ != s_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Oper_LE(string f_, string s_)
{
	return f_ <= s_;
}
bool LO::Oper_LE(int f_, int s_)
{
	return f_ <= s_;
}
bool LO::Oper_LE(bool f_, bool s_)
{
	return f_ <= s_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Oper_GE(string f_, string s_)
{
	return f_ >= s_;
}
bool LO::Oper_GE(int f_, int s_)
{
	return f_ >= s_;
}
bool LO::Oper_GE(bool f_, bool s_)
{
	return f_ >= s_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Oper_L(string f_, string s_)
{
	return f_ < s_;
}
bool LO::Oper_L(int f_, int s_)
{
	return f_ < s_;
}
bool LO::Oper_L(bool f_, bool s_)
{
	return f_ < s_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Oper_G(string f_, string s_)
{
	return f_ > s_;
}
bool LO::Oper_G(int f_, int s_)
{
	return f_ > s_;
}
bool LO::Oper_G(bool f_, bool s_)
{
	return f_ > s_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Oper_AND(bool f_, bool s_)
{
	return f_ && s_;
}
bool LO::Oper_OR(bool f_, bool s_)
{
	return f_ || s_;
}
bool LO::Oper_XOR(bool f_, bool s_)
{
	return (f_ != s_);
}
bool LO::Oper_NOT(bool f_)
{
	return !f_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Oper_CONTAINS(string f_, string s_)
{
	if ( f_.find(s_) != string::npos ) return true;
	else return false;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool LO::Use(string q_, string w_)
{
	return thatf_ds(q_, w_);
}
bool LO::Use(int q_, int w_)
{
	return thatf_di(q_, w_);
}
bool LO::Use(bool q_, bool w_)
{
	return thatf_db(q_, w_);
}
bool LO::Use(bool q_)
{
	return thatf_ub(q_);
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

