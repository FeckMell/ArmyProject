//#include "stdafx.h"
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

			case RevPolNotation::Types::NAME:
				tmp_stack.push(thatGet(boost::any_cast<string>(tmp3.Data())));
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
	if (a_.TypeU() != b_.TypeU())	throw Except("Bad expression");
	Operation* op = boost::any_cast<Operation*>(op_.Data());
	AnyWithType result = op->Use(a_, b_);
	return result;
	//return boost::any_cast<Operation*>(op_)->Use(a_, b_);
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
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------