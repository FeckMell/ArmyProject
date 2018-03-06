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
	std::deque<AnyWithType> GetExpressionRPN();
	std::string GetExpressionSTR();

	//AnyWithType Evulate(...);

private:

	void Init(std::vector<std::string> alphabet_, unsigned mode_);

	std::string thatExpressionSTR;
	std::deque<AnyWithType> thatExpressionRPN;
	std::vector<std::string> thatAlphabet;

	//*///-------------------------------------
	//*///-------------------------------------

	class RevPolNotation_Helper
	{
	public:

		RevPolNotation_Helper(std::string expression_, std::vector<std::string> alphabet_, unsigned mode_);

		std::vector<std::pair<size_t, std::string>> FindOperationPlaces();
		std::string ExpressionClean(std::vector<std::pair<size_t, std::string>> oper_places_);
		std::deque<AnyWithType> ConvertValues(std::vector<AnyWithType> rev_pol_notation_);
		std::vector<AnyWithType> ToRevPolNotation(std::vector<std::pair<size_t, std::string>> operation_places_);

	private:

		void Init(std::vector<std::string> alphabet_, unsigned mode_);

		void RemoveCollisions(std::vector<std::pair<size_t, std::string>>& vec_);
		std::vector<std::string> SplitExpression(std::vector<std::pair<size_t, std::string>> operation_places_);

		/*Sub functions of decisions in algorithm BEGIN*/
		void If_Value(std::string& e_, std::vector<AnyWithType>& result_);
		void If_Op_Stack_Empty(std::stack<std::string>& tmp_stack_, std::string& oper_);
		void If_Op_Brace_Open(std::stack<std::string>& tmp_stack_);
		void If_Op_Brace_Close(std::stack<std::string>& tmp_stack_, std::vector<AnyWithType>& result_);
		void If_Op_Other(std::stack<std::string>& tmp_stack_, std::vector<AnyWithType>& result_, std::string oper_);
		/*Sub functions of decisions in algorithm END*/

		std::string thatExpressionSTR;
		std::deque<AnyWithType> thatExpressionRPN;
		std::vector<std::string> thatAlphabet;

	};

};

