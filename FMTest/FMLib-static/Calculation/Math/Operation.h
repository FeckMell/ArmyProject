#pragma once
#include "stdafx.h"
#include "Interfaces\Str.h"
#include "CommonTypes\DataStorage\AnyWithType.h"

class Operation
{
public:

	enum OpID { EQ, NEQ, GE, LE, G, L, AND, OR, CONTAINS, NOT, BROP, BRCL, MaxOpID };


	static Operation* Get(std::string symbol_, bool delete_ = false);
	AnyWithType Use(AnyWithType& x_, AnyWithType& y_);


	unsigned Id() { return thatId; }
	std::string Symbol() { return thatSymbol; }
	unsigned Priority() { return thatPriority; }
	unsigned ParAmount() { return thatParAmount; }

private:

	Operation(std::string symbol_);
	~Operation() {}

	std::string thatSymbol = "";
	unsigned thatPriority = 0;
	unsigned thatId = 0;
	unsigned thatParAmount = 0;

	AnyWithType Use_EQ(AnyWithType& x_, AnyWithType& y_);
	AnyWithType Use_NEQ(AnyWithType& x_, AnyWithType& y_);
	AnyWithType Use_GE(AnyWithType& x_, AnyWithType& y_);
	AnyWithType Use_LE(AnyWithType& x_, AnyWithType& y_);
	AnyWithType Use_L(AnyWithType& x_, AnyWithType& y_);
	AnyWithType Use_G(AnyWithType& x_, AnyWithType& y_);
	AnyWithType Use_AND(AnyWithType& x_, AnyWithType& y_);
	AnyWithType Use_OR(AnyWithType& x_, AnyWithType& y_);
	AnyWithType Use_CONTAINS(AnyWithType& x_, AnyWithType& y_);


	

};