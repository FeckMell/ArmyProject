#pragma once
#include "stdafx.h"
#include "AnyWithType.h"
#include "LogicOperations.h"
#include "MathOperations.h"
#include "Str.h"
/*Class RevPolNotation turns math expression into 
Reverse Polish Notation*/

class RevPolNotation
{
private:

	typedef RevPolNotation RPN;
	typedef std::string string;

	static std::map<string, AnyWithType> thatOperAlphabet;
	std::deque<AnyWithType> thatExpr;
	std::string thatExprStr;

	string GetSymbol(AnyWithType a_);
	
	void Parse();
	void RemoveCollisions(std::vector<std::pair<size_t, AnyWithType>>* v_);
	void ParseExpr(std::vector<std::pair<size_t, AnyWithType>> v_);

	/**/
	void ParseExprLogic(AnyWithType cur_oper_, std::stack<AnyWithType>& que_);

public:

	enum AlphabetMode {Add, Replace, Remove};
	
	static void Init();
	static void SetOperationAlphabet(std::map<string, AnyWithType> oper_alphabet_, unsigned mode_);
	
	void TestPrint(std::vector<std::pair<size_t, AnyWithType>>);//
	void TestPrint2();///

	RevPolNotation(string expr_);
	void SetExpression(string expr_);
	AnyWithType Evulate(boost::function<AnyWithType(string)> get_);
	

	RevPolNotation() {}
};

