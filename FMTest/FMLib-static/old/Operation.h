#pragma once
#include "stdafx.h"
#include "Interfaces\Str.h"

class Operation
{

private:

	Operation(std::string symbol_);
	~Operation() {}

	std::string thatSymbol = "";
	unsigned thatPriority = 0;
	unsigned thatId = 0;
	unsigned thatParAmount = 0;

public:

	enum OpID { EQ, NEQ, GE, LE, G, L, AND, OR, CONTAINS, NOT, BROP, BRCL, MaxOpID };

	static Operation* Get(std::string symbol_, bool delete_ = false);
	template<class T_, class R_, class E_> void Use(T_& result_, const R_& x, const E_& y);
	template<class T_, class R_> void Use(T_& result_, const R_& x);

	unsigned Id() { return thatId; }
	std::string Symbol() { return thatSymbol; }
	unsigned Priority() { return thatPriority; }
	unsigned ParAmount() { return thatParAmount; }

	//*///------------------------------------------------------------------------------------------
	class EQ
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const unsigned& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);
						
		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const bool& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class NEQ
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);
								
		static bool Use(const bool& x, const unsigned& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);
							
		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const bool& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class GE
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const unsigned& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const bool& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class LE
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const unsigned& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const bool& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class G
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const unsigned& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const bool& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class L
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const unsigned& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const bool& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class AND
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const unsigned& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const bool& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class OR
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const unsigned& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const bool& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class CONTAINS
	{
	public:
		static bool Use(const std::string& x, const unsigned& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const unsigned& x, const unsigned& y);
		static bool Use(const unsigned& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class NOT
	{
	public:
		static bool Use(const std::string& x);

		static bool Use(const unsigned& x);

		static bool Use(const bool& x);
	};
	//*///------------------------------------------------------------------------------------------

};

//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class T_, class R_, class E_> void Operation::Use(T_& result_, const R_& x_, const E_& y_)
{
	switch (thatId)
	{
		case EQ: result_ = EQ::Use(x_, y_); return;
		case NEQ: result_ = NEQ::Use(x_, y_); return;
		case GE: result_ = GE::Use(x_, y_); return;
		case LE: result_ = LE::Use(x_, y_); return;
		case L: result_ = L::Use(x_, y_); return;
		case G: result_ = G::Use(x_, y_); return;
		case AND: result_ = AND::Use(x_, y_); return;
		case OR: result_ = OR::Use(x_, y_); return;
		case CONTAINS: result_ = OR::Use(x_, y_); return;
		default: throw Except("Bad data");
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
template<class T_, class R_> void Use(T_& result_, const R_& x_)
{
	switch (thatId)
	{
		case NOT: result_ = NOT::Use(x_); return;
		default: throw Except("Bad data");
	}
}

