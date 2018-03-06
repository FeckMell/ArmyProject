#pragma once
#include "stdafx.h"
#include "CommonTypes\DataStorage\AnyWithType.h"
#include "Calculation\Math\Operation.h"
#include "Interfaces\Str.h"
#include "Interfaces\VEC.h"

/*Class RevPolNotation turns math expression into 
Reverse Polish Notation*/

/*Except:
"Bad expression"
"Expression empty"
*/
class RevPolNotation
{
public:

	enum AlphabetMode {Add, Replace, Remove};
	~RevPolNotation(){}

	RevPolNotation(std::string expression_, std::vector<std::string> alphabet_ = {}, unsigned mode_ = 0);
	AnyWithType Evulate(...);

private:

	void Parse();
	void Init(std::vector<std::string> alphabet_, unsigned mode_);

	std::vector<std::pair<size_t, std::string>> FindOperationPlaces();
	void RemoveCollisions(std::vector<std::pair<size_t, std::string>>& vec_);
	void ExpressionClean(std::vector<std::pair<size_t, std::string>> oper_places_);

	std::vector<AnyWithType> ToRevPolNotation(std::vector<std::pair<size_t, std::string>> operation_places_);
	std::vector<std::string> SplitExpression(std::vector<std::pair<size_t, std::string>> operation_places_);
	std::deque<AnyWithType> ConvertValues(std::vector<AnyWithType> rev_pol_notation_);

	std::string thatExpressionSTR;
	std::deque<AnyWithType> thatExpressionRPN;
	std::vector<std::string> thatAlphabet;

};

