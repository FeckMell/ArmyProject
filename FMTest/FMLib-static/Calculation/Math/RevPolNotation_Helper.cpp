#include "stdafx.h"
#include "Calculation\Math\RevPolNotation.h"

using namespace std;

RevPolNotation::RevPolNotation_Helper::RevPolNotation_Helper(string expression_, vector<string> alphabet_, unsigned mode_)
{
	/*Remember expression in helper*/
	thatExpressionSTR = expression_;

	/*Set alphabet for this session*/
	Init(alphabet_, mode_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RevPolNotation::RevPolNotation_Helper::Init(vector<string> alphabet_, unsigned mode_)
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
vector<pair<size_t, string>> RevPolNotation::RevPolNotation_Helper::FindOperationPlaces()
{
	vector<size_t> tmp;
	vector<pair<size_t, string>> result;

	/*Find all places of operations*/
	for (auto& e : thatAlphabet)
	{
		tmp = STR::FindInStrAll(thatExpressionSTR, e);
		for (auto& t : tmp) result.push_back({ t, e });
	}

	/*sort to parse in right order and remove collisions*/
	VEC::Sort_M<pair<size_t, string>>(result, [](pair<size_t, string>& a, pair<size_t, string>& b){return a.first < b.first; });
	RemoveCollisions(result);

	/*return to main class*/
	return result;
}
//*///------------------------------------------------------------------------------------------ 
//*///------------------------------------------------------------------------------------------
void RevPolNotation::RevPolNotation_Helper::RemoveCollisions(vector<pair<size_t, string>>& vec_)
{
	if (vec_.empty()) throw Except("Bad expression");

	unsigned i = 0;
	while (i < vec_.size() - 1)
	{
		/*if operations have same positions*/
		if (vec_[i].first == vec_[i + 1].first)
		{
			/*if first is longer then second -> remove second
			if something removed - do NOT encrease counter!!!*/
			if (vec_[i].second.length()>vec_[i + 1].second.length())
			{
				vec_.erase(vec_.begin() + i + 1);
				continue;
			}
			else
			{
				vec_.erase(vec_.begin() + i);
				continue;
			}
		}
		/*Increase counter!!!*/
		++i;
	}
}
//*///------------------------------------------------------------------------------------------ 
//*///------------------------------------------------------------------------------------------
string RevPolNotation::RevPolNotation_Helper::ExpressionClean(vector<pair<size_t, string>> oper_places_)
{
	/*copy expression. Delete this later*/
	string expr = thatExpressionSTR;

	/*Go throw all operation from end (as their places will change otherwise)*/
	unsigned i = oper_places_.size() - 1;
	while (i < oper_places_.size())
	{
		/*and add to their symbols extra spaces in front and behind them*/
		expr.replace(oper_places_[i].first, oper_places_[i].second.length(), " " + oper_places_[i].second + " ");

		/*DEcrease counter*/
		--i;
	}

	/*Delete double spaces*/
	expr = STR::ReplaceInStrAll(expr, "  ", " ");

	/*Delete extra space in front and back of expression*/
	if (expr.front() == ' ') expr.erase(expr.front());
	if (expr.back() == ' ') expr.pop_back();

	/*replace expression in helper*/
	thatExpressionSTR = expr;

	/*return to main class*/
	return expr;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<AnyWithType> RevPolNotation::RevPolNotation_Helper::ToRevPolNotation(vector<pair<size_t, string>> oper_places_)
{
	/*See logic of this convertion in algorithms in the Internet: http://www.interface.ru/home.asp?artId=1492 */
	/*Init parsing*/
	vector<AnyWithType> result;
	stack<string> tmp_stack;
	vector<string> expr;
	string tmp_oper;
	string tmp_str;

	/*Split thatExpressionSTR to values, names and operations in order as in thatExpressionSTR*/
	expr = SplitExpression(oper_places_);

	/*Convert to Reverse Polish Notation*/
	unsigned i = 0;
	for (auto& e : expr)
	{
		if (i < oper_places_.size())	/*Check for possible errors*/
		{
			tmp_oper = oper_places_[i].second;
			/*if e is value or name*/
			if (e != tmp_oper) If_Value(e, result);
			/*if e is operation*/
			else
			{
				if (tmp_stack.empty())
					If_Op_Stack_Empty(tmp_stack, tmp_oper);
				else if (tmp_oper == "(")
					If_Op_Brace_Open(tmp_stack);
				else if (tmp_oper == ")")
					If_Op_Brace_Close(tmp_stack, result);
				else
					If_Op_Other(tmp_stack, result, tmp_oper);

				/*switch to next operation*/
				++i;
			}
		}
		else if (i == oper_places_.size())	 /*case when operation is not last element in expr*/
		{
			if (e != tmp_oper) If_Value(e, result);
			else throw Except("Bad expression");
		}
		else throw Except("Bad expression");	 /*Something stange. In any case it`s an error*/
	}

	/*When finished parsing need to extract operations from @tmp_stack to @result*/
	while (!tmp_stack.empty())
	{
		result.push_back(AnyWithType(Operation::Get(tmp_stack.top()), "Operation"));
		tmp_stack.pop();
	}

	/*return to main class*/
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
vector<string> RevPolNotation::RevPolNotation_Helper::SplitExpression(vector<pair<size_t, string>> oper_places_)
{
	/*Init*/
	vector<string> result;

	/*Add 0 and string::npos operation to parse everything in cycle*/
	oper_places_.insert(oper_places_.begin(), { 0, "" });
	oper_places_.push_back({ string::npos, "" });

	/*Get all substrings between operations*/
	for (unsigned i = 0; i<oper_places_.size() - 1; ++i)
	{
		result.push_back(oper_places_[i].second);
		result.push_back(STR::SubStrFromTo(thatExpressionSTR, oper_places_[i].first + oper_places_[i].second.length(), oper_places_[i + 1].first));
	}

	/*Delete empty elements and space elements*/
	for (unsigned i = 0; i < result.size(); ++i)
	{
		if (result[i].empty()) result.erase(result.begin() + i);
		else if (result[i] == " ") result.erase(result.begin() + i);
	}

	/*Clean arguments from extra spaces*/
	for (auto& e : result)
	{
		if (e.front() == ' ') e.erase(e.begin());
		if (e.back() == ' ') e.pop_back();
	}

	/*Delete string::npos operation*/
	//oper_places_.pop_back();

	/*return to helper class*/
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
deque<AnyWithType> RevPolNotation::RevPolNotation_Helper::ConvertValues(vector<AnyWithType> rpn_)
{
	/*Init*/
	deque<AnyWithType> result;
	string tmp_data;
	string tmp_val;

	/*Converting*/
	for (auto& e : rpn_)
	{
		if (e.TypeS() == "Value")
		{
			tmp_data = boost::any_cast<string>(e.Data());
			tmp_val = STR::SubStrFromTo(tmp_data, 0, 2);
			if (tmp_val == "N:")
				result.push_back(AnyWithType(STR::SubStrFromTo(tmp_data, 2, string::npos), "Name"));
			else if (tmp_val == "V:")
				result.push_back(AnyWithType(STR::SubStrFromTo(tmp_data, 2, string::npos), "Value"));
			else throw Except("Bad expression");
		}
		else result.push_back(e);
	}

	/*return to main class*/
	return result;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RevPolNotation::RevPolNotation_Helper::If_Value(string& e_, vector<AnyWithType>& result_)
{
	result_.push_back(AnyWithType(e_, "Value"));
}
//*///-------------------------------------
//*///-------------------------------------
void RevPolNotation::RevPolNotation_Helper::If_Op_Stack_Empty(stack<string>& tmp_stack_, string& oper_)
{
	tmp_stack_.push(oper_);
}
//*///-------------------------------------
//*///-------------------------------------
void RevPolNotation::RevPolNotation_Helper::If_Op_Brace_Open(stack<string>& tmp_stack_)
{
	tmp_stack_.push("(");
}
//*///-------------------------------------
//*///-------------------------------------
void RevPolNotation::RevPolNotation_Helper::If_Op_Brace_Close(stack<string>& tmp_stack_, vector<AnyWithType>& result_)
{

	/*Extract operations from stack until "(" or stack empty(error)*/
	if (tmp_stack_.empty()) throw Except("Bad expression");
	string last_oper = tmp_stack_.top();

	while (last_oper != "(")
	{
		result_.push_back(AnyWithType(Operation::Get(last_oper), "Operation"));
		tmp_stack_.pop();

		if (tmp_stack_.empty()) throw Except("Bad expression");
		last_oper = tmp_stack_.top();
	}

	/*Delete operation "(" */
	tmp_stack_.pop();
}
//*///-------------------------------------
//*///-------------------------------------
void RevPolNotation::RevPolNotation_Helper::If_Op_Other(stack<string>& tmp_stack_, vector<AnyWithType>& result_, string oper_)
{
	unsigned this_priority = Operation::Get(oper_)->Priority();
	unsigned temp_priority = Operation::Get(tmp_stack_.top())->Priority();
	if (temp_priority < this_priority)
	{
		tmp_stack_.push(oper_);
	}
	else
	{
		while (!tmp_stack_.empty())
		{
			temp_priority = Operation::Get(tmp_stack_.top())->Priority();

			if (temp_priority < this_priority)
			{
				result_.push_back(AnyWithType(Operation::Get(oper_), "Operation"));
				break;
			}
			else
			{
				result_.push_back(AnyWithType(Operation::Get(tmp_stack_.top()), "Operation"));
				tmp_stack_.pop();
			}
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