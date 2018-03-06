#pragma once
#include "stdafx.h"
#include "Except.h"
#include "Str.h"


class Evulation2
{
public:
	
	template<class T_, class R_> static bool Op_EQ(T_ a, R_ b) { return EQ::eq(a, b); }
	template<class T_, class R_> static bool Op_NEQ(T_ a, R_ b) { return NEQ::neq(a, b); }


private:

	Evulation2()	{}
	~Evulation2(){}
	//*///------------------------------------------------------------------------------------------
	//*///------------------------------------------------------------------------------------------
	class EQ
	{
	public:
		static bool eq(const std::string& x, const int& y);
		static bool eq(const std::string& x, const bool& y);
		static bool eq(const std::string& x, std::string& y);
		
		static bool eq(const bool& x, const int& y);
		static bool eq(const bool& x, const bool& y);
		static bool eq(const bool& x, const std::string& y);
		
		static bool eq(const int& x, const int& y);
		static bool eq(const int& x, const bool& y);
		static bool eq(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	class NEQ
	{
	public:
		static bool neq(const std::string& x, const int& y);
		static bool neq(const std::string& x, const bool& y);
		static bool neq(const std::string& x, std::string& y);
								
		static bool neq(const bool& x, const int& y);
		static bool neq(const bool& x, const bool& y);
		static bool neq(const bool& x, const std::string& y);
								
		static bool neq(const int& x, const int& y);
		static bool neq(const int& x, const bool& y);
		static bool neq(const int& x, const std::string& y);
	};
	//*///------------------------------------------------------------------------------------------
	//*///------------------------------------------------------------------------------------------
};


