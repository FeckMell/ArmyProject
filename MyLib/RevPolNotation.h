#pragma once
#include "stdafx.h"
#include "AnyWithType.h"
/*Class RevPolNotation turns math expression into 
Reverse Polish Notation*/

class RevPolNotation
{
private:

	typedef RevPolNotation RPN;
	typedef std::string string;

	std::deque<AnyWithType> thatExpr;
	std::string thatExprStr;

	void Parse();

public:

	RevPolNotation(string expr_);
	void SetExpression(string expr_);

	RevPolNotation() {}
};

