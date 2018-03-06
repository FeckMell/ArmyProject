#pragma once
#include "stdafx.h"
#include "Str.h"

class Operation
{
public:

	static Operation* Get(std::string symbol_, bool delete_ = false);

	unsigned Id() { return thatId; }
	std::string Symbol() { return thatSymbol; }
	unsigned Priority() { return thatPriority; }
	bool IsBinary() { return thatBinary; }

	//*///------------------------------------------------------------------------------------------
	class EQ
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, std::string& y);

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
		static bool Use(const std::string& x, std::string& y);
								
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
		static bool Use(const std::string& x, std::string& y);

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
		static bool Use(const std::string& x, std::string& y);

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
		static bool Use(const std::string& x, std::string& y);

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
		static bool Use(const std::string& x, std::string& y);

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
		static bool Use(const std::string& x, std::string& y);

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
		static bool Use(const std::string& x, std::string& y);

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
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	/*class NOT
	{
	public:
		static bool Use(const std::string& x, const int& y);
		static bool Use(const std::string& x, const bool& y);
		static bool Use(const std::string& x, std::string& y);

		static bool Use(const bool& x, const int& y);
		static bool Use(const bool& x, const bool& y);
		static bool Use(const bool& x, const std::string& y);

		static bool Use(const int& x, const int& y);
		static bool Use(const int& x, const bool& y);
		static bool Use(const int& x, const std::string& y);
	};*/

	
private:

	Operation(std::string symbol_);
	~Operation() {}

	std::string thatSymbol = "";
	unsigned thatPriority = 0;
	unsigned thatId = 0;
	bool thatBinary = 0;


};

