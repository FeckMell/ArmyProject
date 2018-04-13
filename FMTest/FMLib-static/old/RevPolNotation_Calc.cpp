#include "stdafx.h"
#include "Calculation\Math\RevPolNotation.h"
using namespace std;

RevPolNotation::RevPolNotation_Calc::RevPolNotation_Calc(boost::function<AnyWithType(string)> get_, deque<AnyWithType> rpn_)
{
	thatGet = get_;
	thatExpressionRPN = rpn_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
AnyWithType RevPolNotation::RevPolNotation_Calc::Evulate()
{
	/*Init calculation*/
	stack<AnyWithType> tmp_stack;
	AnyWithType tmp1;
	AnyWithType tmp2;
	AnyWithType tmp3;

	while (!thatExpressionRPN.empty())
	{
		tmp3 = thatExpressionRPN.front();	thatExpressionRPN.pop_front();
		switch (tmp3.TypeU())
		{
			case RevPolNotation::Types::OPERATION:
				if (tmp_stack.size() < 2) throw Except("Bad expression");
				tmp1 = tmp_stack.top(); tmp_stack.pop();
				tmp2 = tmp_stack.top(); tmp_stack.pop();
				tmp_stack.push(Case_Operation(tmp1, tmp2, tmp3));
				break;

			default:
				tmp_stack.push(tmp3);
				break;
		}
	}

	/*Check that we achieved result*/
	if (tmp_stack.size() != 1) throw Except("Bad expression");

	/*Last element in stack is result*/
	return tmp_stack.top();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
AnyWithType RevPolNotation::RevPolNotation_Calc::Case_Operation(AnyWithType& a_, AnyWithType& b_, AnyWithType& op_)
{
	unsigned type_a = a_.TypeU();
	unsigned type_b = b_.TypeU();
	if (type_a == RevPolNotation::Types::NAME && type_b == RevPolNotation::Types::NAME)
	{
		AnyWithType tmp1 = thatGet(boost::any_cast<string>(a_.Data()));
		AnyWithType tmp2 = thatGet(boost::any_cast<string>(b_.Data()));
		if (tmp1.TypeU() != tmp2.TypeU())	throw Except("Bad expression");
		return boost::any_cast<Operation*>(op_)->Use(tmp1, tmp2);
	}
	else if (type_a == RevPolNotation::Types::NAME)
	{
		AnyWithType tmp = thatGet(boost::any_cast<string>(a_.Data()));
		if (tmp.TypeU() != type_b) throw Except("Bad expression");
		return boost::any_cast<Operation*>(op_)->Use(tmp, b_);
	}
	else if (type_b == RevPolNotation::Types::NAME)
	{
		AnyWithType tmp = thatGet(boost::any_cast<string>(b_.Data()));
		if (tmp.TypeU() != type_a) throw Except("Bad expression");
		return boost::any_cast<Operation*>(op_)->Use(a_, tmp);
	}
	else if (type_a == type_b)
	{
		return boost::any_cast<Operation*>(op_)->Use(a_, b_);
	}
	else throw Except("Bad expression");
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
AnyWithType Type_Switch(AnyWithType& a_, AnyWithType& b_, AnyWithType& op_)
{
	
	bool result;
	switch (a_.TypeU())
	{
		case AnyWithType::BOOL: 
			boost::any_cast<Operation*>(op_.Data())->Use<bool, bool>(
				result,
				boost::any_cast<bool>(a_.Data()),
				boost::any_cast<bool>(b_.Data())
				);
			return AnyWithType(result, AnyWithType::BOOL);

		case AnyWithType::INT: 
			boost::any_cast<Operation*>(op_.Data())->Use<bool, int>(
				result,
				boost::any_cast<int>(a_.Data()),
				boost::any_cast<int>(b_.Data())
				);
			return AnyWithType(result, AnyWithType::BOOL);

		case AnyWithType::UNSIGNED: 
			boost::any_cast<Operation*>(op_.Data())->Use<bool, unsigned>(
				result,
				boost::any_cast<unsigned>(a_.Data()),
				boost::any_cast<unsigned>(b_.Data())
				);
			return AnyWithType(result, AnyWithType::BOOL);

		case AnyWithType::STRING: 
			boost::any_cast<Operation*>(op_.Data())->Use<bool, string>(
				result,
				boost::any_cast<string>(a_.Data()),
				boost::any_cast<string>(b_.Data())
				);
			return AnyWithType(result, AnyWithType::BOOL);

		default: throw Except("Bad expression");
		/*case AnyWithType::DOUBLE:*/
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------