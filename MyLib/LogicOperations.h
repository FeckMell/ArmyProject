#pragma once
class LogicOperations
{
private:

	typedef std::string string;

	string thatSymbol="";
	unsigned thatPriority=0;
	bool thatBinary = 0;

	bool(*thatf_ds)(string, string);
	bool(*thatf_di)(int, int);
	bool(*thatf_db)(bool,bool);
	bool(*thatf_ub)(bool);

	static bool Oper_EQ(string, string);
	static bool Oper_EQ(int, int);
	static bool Oper_EQ(bool, bool);

	static bool Oper_NEQ(string, string);
	static bool Oper_NEQ(int, int);
	static bool Oper_NEQ(bool, bool);

	static bool Oper_LE(string, string);
	static bool Oper_LE(int, int);
	static bool Oper_LE(bool, bool);

	static bool Oper_GE(string, string);
	static bool Oper_GE(int, int);
	static bool Oper_GE(bool, bool);

	static bool Oper_L(string, string);
	static bool Oper_L(int, int);
	static bool Oper_L(bool, bool);

	static bool Oper_G(string, string);
	static bool Oper_G(int, int);
	static bool Oper_G(bool, bool);

	static bool Oper_AND(bool, bool);
	static bool Oper_OR(bool, bool);
	static bool Oper_XOR(bool, bool);
	static bool Oper_NOT(bool);

	static bool Oper_CONTAINS(string, string);
	static bool Oper_fake(bool) { return false; }

public:

	string Symbol() { return thatSymbol; }
	unsigned Priority() { return thatPriority; }
	bool IsBinary() { return thatBinary; }

	bool Use(string, string);
	bool Use(int, int);
	bool Use(bool, bool);
	bool Use(bool);

	LogicOperations(string symbol_);
	LogicOperations() {}
	~LogicOperations() {}
};

