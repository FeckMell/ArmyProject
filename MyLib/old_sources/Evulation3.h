#pragma once
#include "stdafx.h"
#include "Except.h"
#include "Str.h"

class Evulation3
{
public:

	template<class T_, class R_> static bool Op_EQ(T_ a, R_ b) { return a == b; }
	template<class T_, class R_> static bool Op_NEQ(T_ a, R_ b) { return a != b; }
	template<class T_, class R_> static bool Op_GE(T_ a, R_ b) { return a >= b; }
	template<class T_, class R_> static bool Op_LE(T_ a, R_ b) { return a <= b; }
	template<class T_, class R_> static bool Op_G(T_ a, R_ b) { return a > b; }
	template<class T_, class R_> static bool Op_L(T_ a, R_ b) { return a < b; }
	template<class T_, class R_> static bool Op_XOR(T_ a, R_ b) { return a != b; }
	template<class T_, class R_> static bool Op_AND(T_ a, R_ b) { return a && b; }
	template<class T_, class R_> static bool Op_OR(T_ a, R_ b) { return a || b; }
	template<class T_, class R_> static bool Op_CONTAINS(T_ a, R_ b) { return _Contains(a, b); }
	template<class T_, class R_> static bool Op_IN(T_ a, R_ b) { return _In(a, b); }
	template<class T_> static bool Op_NOT(T_ a) { return !a; }


private:

	typedef std::string string;
	Evulation3() {}
	~Evulation3() {}

	/*LOGIC OPERATIONS*/
	//*///------------------------------------------------------------------------------------------
	friend bool operator== (const string& x, const bool& y);
	friend bool operator== (const bool& x, const string& y);
	friend bool operator== (const string& x, const int& y);
	friend bool operator== (const int& x, const string& y);

	friend bool operator!= (const string& x, const bool& y);
	friend bool operator!= (const bool& x, const string& y);
	friend bool operator!= (const string& x, const int& y);
	friend bool operator!= (const int& x, const string& y);

	friend bool operator>= (const std::string& x, const int& y);
	friend bool operator>= (const int& x, const std::string& y);
	friend bool operator>= (const std::string& x, const std::string& y);

	friend bool operator<= (const std::string& x, const int& y);
	friend bool operator<= (const int& x, const std::string& y);
	friend bool operator<= (const std::string& x, const std::string& y);

	friend bool operator> (const std::string& x, const int& y);
	friend bool operator> (const int& x, const std::string& y);
	friend bool operator> (const std::string& x, const std::string& y);

	friend bool operator< (const std::string& x, const int& y);
	friend bool operator< (const int& x, const std::string& y);
	friend bool operator< (const std::string& x, const std::string& y);

	friend bool operator&& (const std::string& x, const bool& y);
	friend bool operator&& (const bool& x, const std::string& y);
	friend bool operator&& (const std::string& x, const int& y);
	friend bool operator&& (const int& x, const std::string& y);

	friend bool operator|| (const std::string& x, const bool& y);
	friend bool operator|| (const bool& x, const std::string& y);
	friend bool operator|| (const std::string& x, const int& y);
	friend bool operator|| (const int& x, const std::string& y);

	friend bool operator! (const std::string& x);

	bool _Contains(const std::string& x, const bool& y) { return (x.find(std::to_string(y)) != std::string::npos); }
	bool _Contains(const bool& x, const std::string& y) { return (std::to_string(x).find(y) != std::string::npos); }
	bool _Contains(const std::string& x, const int& y) { return (x.find(std::to_string(y)) != std::string::npos); }
	bool _Contains(const int& x, const std::string& y) { return (std::to_string(x).find(y) != std::string::npos); }
	bool _Contains(const std::string& x, const std::string& y) { return (x.find(y) != std::string::npos); }

	bool _In(const std::string& x, const bool& y);
	bool _In(const std::string& x, const int& y);
	bool _In(const std::string& x, const std::string& y);
	bool _In(const bool& x, const std::string& y);
	bool _In(const int& x, const std::string& y);
	/*END LOGIC OPERATIONS*/
	//*///------------------------------------------------------------------------------------------
};
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
/*LOGIC OPERATIONS*/
bool operator==(const std::string& x, const bool& y) { return x == std::to_string(y); }
bool operator==(const bool& x, const std::string& y) { return std::to_string(x) == y; }
bool operator==(const std::string& x, const int& y) { return x == std::to_string(y); }
bool operator==(const int& x, const std::string& y) { return std::to_string(x) == y; }

bool operator!=(const std::string& x, const bool& y) { return x != std::to_string(y); }
bool operator!=(const bool& x, const std::string& y) { return std::to_string(x) != y; }
bool operator!=(const std::string& x, const int& y) { return x != std::to_string(y); }
bool operator!=(const int& x, const std::string& y) { return std::to_string(x) != y; }

bool operator>=(const std::string& x, const int& y) { return STR::ToInt(x) >= y; }
bool operator>=(const int& x, const std::string& y) { return x >= STR::ToInt(y); }
bool operator>=(const std::string& x, const std::string& y) { return x.length() >= y.length(); }

bool operator<=(const std::string& x, const int& y) { return STR::ToInt(x) <= y; }
bool operator<=(const int& x, const std::string& y) { return x <= STR::ToInt(y); }
bool operator<=(const std::string& x, const std::string& y) { return x.length() <= y.length(); }

bool operator> (const std::string& x, const int& y) { return STR::ToInt(x) > y; }
bool operator> (const int& x, const std::string& y) { return x > STR::ToInt(y); }
bool operator> (const std::string& x, const std::string& y) { return x.length() > y.length(); }

bool operator< (const std::string& x, const int& y) { return STR::ToInt(x) < y; }
bool operator< (const int& x, const std::string& y) { return x < STR::ToInt(y); }
bool operator< (const std::string& x, const std::string& y) { return x.length() < y.length(); }

bool operator&& (const std::string& x, const bool& y) { return (STR::ToBool(x) && y); }
bool operator&& (const bool& x, const std::string& y) { return (x && STR::ToBool(y)); }
bool operator&& (const std::string& x, const int& y) { return (STR::ToInt(x) && y); }
bool operator&& (const int& x, const std::string& y) { return (x && STR::ToInt(y)); }

bool operator|| (const std::string& x, const bool& y) { return (STR::ToBool(x) || y); }
bool operator|| (const bool& x, const std::string& y) { return (x || STR::ToBool(y)); }
bool operator|| (const std::string& x, const int& y) { return (STR::ToInt(x) || y); }
bool operator|| (const int& x, const std::string& y) { return (x || STR::ToInt(y)); }

bool operator! (const std::string& x) { return !STR::ToBool(x); }
/*END LOGIC OPERATIONS*/
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------