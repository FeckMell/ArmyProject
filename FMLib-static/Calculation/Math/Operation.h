#pragma once
#include "stdafx.h"
#include "Interfaces\Str.h"

class Operation
{
public:

	enum OpID { EQ, NEQ, GE, LE, G, L, AND, OR, CONTAINS, NOT, BROP, BRCL, MaxOpID };

	static Operation* Get(std::string symbol_, bool delete_ = false);

	unsigned Id() { return thatId; }
	std::string Symbol() { return thatSymbol; }
	unsigned Priority() { return thatPriority; }
	unsigned ParAmount() { return thatParAmount; }

	//*///------------------------------------------------------------------------------------------
	class EQ
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);
						
		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class NEQ
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);
								
		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);
							
		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class GE
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class LE
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class G
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class L
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class AND
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class OR
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class CONTAINS
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class NOT
	{
	public:
		static bool Use(const std::string& x);

		static bool Use(const int& x);

		static bool Use(const bool& x);
	};
	//*///------------------------------------------------------------------------------------------


private:

	Operation(std::string symbol_);
	~Operation() {}

	std::string thatSymbol = "";
	unsigned thatPriority = 0;
	unsigned thatId = 0;
	unsigned thatParAmount = 0;


};

