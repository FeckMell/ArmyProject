#pragma once
#include "stdafx.h"
#include "CommonTypes\DataStorage\AnyWithType.h"
#include "Calculation\Math\Operation.h"
#include "Interfaces\Str.h"

/*Class RevPolNotation turns math expression into 
Reverse Polish Notation*/

class RevPolNotation
{
private:

	static std::map<std::string, AnyWithType> thatOperAlphabet;
	std::deque<AnyWithType> thatExpr;
	std::string thatExprStr;

	std::string GetSymbol(AnyWithType a_);
	
	void Parse();
	void RemoveCollisions(std::vector<std::pair<size_t, AnyWithType>>* v_);
	void ParseExpr(std::vector<std::pair<size_t, AnyWithType>> v_);

	/**/
	void ParseExprLogic(AnyWithType cur_oper_, std::stack<AnyWithType>& que_);

public:

	enum AlphabetMode {Add, Replace, Remove};
	
	static void Init();
	static void SetOperationAlphabet(std::map<std::string, AnyWithType> oper_alphabet_, unsigned mode_);
	
	void TestPrint(std::vector<std::pair<size_t, AnyWithType>>);//
	void TestPrint2();///

	RevPolNotation(std::string expr_);
	void SetExpression(std::string expr_);
	AnyWithType Evulate(boost::function<AnyWithType(std::string)> get_);
	

	RevPolNotation() {}
};

