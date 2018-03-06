#pragma once
//#include "stdafx.h"
#include <boost\function.hpp>
#include "CommonTypes\DataStorage\AnyWithType.h"
#include "Calculation\Math\Operation.h"
#include "Interfaces\Str.h"
#include "Interfaces\VEC.h"

/*Class RevPolNotation turns math expression into 
Reverse Polish Notation*/

/*Except:
"Bad expression"
"Expression empty"
"Call error"
*/

class RevPolNotation
{
public:

	enum AlphabetMode { Add, Replace, Remove, AlphabetMode_Max };
	~RevPolNotation(){}

	RevPolNotation(std::string expression_, std::vector<std::string> alphabet_ = {}, unsigned mode_ = 0);
	AnyWithType Evulate(boost::function<AnyWithType(std::string)> get_);


	/*Info*/
	std::deque<AnyWithType> GetExpressionRPN();
	std::string GetExpressionSTR();
	std::string ToString();
	/*Info*/


private:

	enum Types{ VALUE = AnyWithType::MaxType + 1, NAME, OPERATION, Types_Max };

	void Init(std::vector<std::string> alphabet_, unsigned mode_);

	std::string thatExpressionSTR;
	std::deque<AnyWithType> thatExpressionRPN;
	std::vector<std::string> thatAlphabet;

	//*///-------------------------------------
	//*///-------------------------------------
	//*///-------------------------------------
	//*///-------------------------------------

	class RevPolNotation_Parser
	{
	public:

		RevPolNotation_Parser(std::string expression_, std::vector<std::string> alphabet_, unsigned mode_);

		std::vector<std::pair<size_t, std::string>> FindOperationPlaces(std::string expression_);
		std::string ExpressionClean(std::vector<std::pair<size_t, std::string>> oper_places_, std::string expression_);
		std::deque<AnyWithType> ConvertValues(std::vector<AnyWithType> rev_pol_notation_);
		std::vector<AnyWithType> ToRevPolNotation(std::vector<std::pair<size_t, std::string>> operation_places_, std::string expression_);

	private:

		void Init(std::vector<std::string> alphabet_, unsigned mode_);

		void RemoveCollisions(std::vector<std::pair<size_t, std::string>>& vec_);
		std::vector<std::string> SplitExpression(std::vector<std::pair<size_t, std::string>> operation_places_, std::string expression_);

		/*Sub functions of decisions in algorithm BEGIN*/
		void If_Value(std::string& e_, std::vector<AnyWithType>& result_);
		void If_Op_Stack_Empty(std::stack<std::string>& tmp_stack_, std::string& oper_);
		void If_Op_Brace_Open(std::stack<std::string>& tmp_stack_);
		void If_Op_Brace_Close(std::stack<std::string>& tmp_stack_, std::vector<AnyWithType>& result_);
		void If_Op_Other(std::stack<std::string>& tmp_stack_, std::vector<AnyWithType>& result_, std::string oper_);
		/*Sub functions of decisions in algorithm END*/

		//std::string thatExpressionSTR;
		std::deque<AnyWithType> thatExpressionRPN;
		std::vector<std::string> thatAlphabet;

	};
	//*///-------------------------------------
	//*///-------------------------------------
	//*///-------------------------------------
	//*///-------------------------------------
	class RevPolNotation_Calc
	{
	public:
		RevPolNotation_Calc(boost::function<AnyWithType(std::string)> get_, std::deque<AnyWithType> rpn_);

		AnyWithType Evulate();

	private:

		AnyWithType Case_Operation(AnyWithType& a_, AnyWithType& b_, AnyWithType& op_);
		AnyWithType Type_Switch(AnyWithType& a_, AnyWithType& b_, AnyWithType& op_);

		boost::function<AnyWithType(std::string)> thatGet;
		std::deque<AnyWithType> thatExpressionRPN;

	};
};

