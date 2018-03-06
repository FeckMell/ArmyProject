#include "stdafx.h"
#include "RevPolNotation.h"

using namespace std;


//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
RevPolNotation::RevPolNotation(string expression_, vector<string> alphabet_, unsigned mode_)
{
	if (expression_.empty()) throw Except("Expression empty");

	/*Init Operations and @thatAlphabet*/
	Init(alphabet_, mode_);

	/*Create and init helper which parses expression*/
	RevPolNotation_Helper helper(expression_, alphabet_, mode_);

	/*Init parsing*/
	vector<pair<size_t, string>> oper_places;
	vector<AnyWithType> rev_pol_notation;

	/*Get places of operations to use them as tombstones*/
	oper_places = helper.FindOperationPlaces();

	/*Make thatExpressionSTR more clear*/
	thatExpressionSTR = helper.ExpressionClean(oper_places);

	/*Get places of operations again as they changed*/
	oper_places = helper.FindOperationPlaces();

	/*Parse expression*/
	rev_pol_notation = helper.ToRevPolNotation(oper_places);

	/*Convert values and name in RPN to define what is value and what is parameter to get from storage*/
	thatExpressionRPN = helper.ConvertValues(rev_pol_notation);
}
//*///------------------------------------------------------------------------------------------ 
//*///------------------------------------------------------------------------------------------
deque<AnyWithType> RevPolNotation::GetExpressionRPN()
{
	return thatExpressionRPN;
}
//*///------------------------------------------------------------------------------------------ 
//*///------------------------------------------------------------------------------------------
string RevPolNotation::GetExpressionSTR()
{
	return thatExpressionSTR;
}
//*///------------------------------------------------------------------------------------------ 
//*///------------------------------------------------------------------------------------------
void RevPolNotation::Init(vector<string> alphabet_, unsigned mode_)
{
	/* if empty, then default alphabet*/
	if (alphabet_.empty())
	{
		thatAlphabet = { "==", "!=", ">=", "<=", ">", "<", "&&", "||", "^^", "!", "contains", "(", ")" };
	}
	else
	{
		switch (mode_)
		{
			case Add:
				for (auto& e : alphabet_) thatAlphabet.push_back(e);
				VEC::RemoveCollisions_M<string>(thatAlphabet, [](string a, string b){return a == b; });
				break;

			case Remove:
				for (auto& e : alphabet_) VEC::DelALL_M<string>(thatAlphabet, e, [](string a, string b){return a == b; });
				break;

			case Replace:
				thatAlphabet = alphabet_;
				break;
		}
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
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------


