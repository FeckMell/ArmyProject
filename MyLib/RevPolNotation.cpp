#include "stdafx.h"
#include "RevPolNotation.h"

using namespace std;
typedef RevPolNotation RPN;
map<string, AnyWithType> RPN::thatOperAlphabet = {};

void RPN::TestPrint(vector<pair<size_t, AnyWithType>> v)
{
	cout << "\n\nPOSITION OF OPERATIONS";
	for ( auto& e : v )
	{
		cout << "\nPosition=_" << e.first << "_ symbol=_" << GetSymbol(e.second) << "_";
	}
}
void RPN::TestPrint2()
{
	cout << "\nTEST PRINT 2:\n";

	for ( auto& e : thatExpr )
	{
		if ( e.TypeS() == "string" )
		{
			cout << "_" << boost::any_cast<string>(e.Data()) << "_";
		}
		else if ( e.TypeS() == "LogicOperations" )
		{
			cout << "_" << boost::any_cast<LogicOperations>(e.Data()).Symbol() << "_";
		}
		else
		{
			cout << "\n PROBLEM!";
		}
	}
}

RPN::RevPolNotation(string expr_) :thatExprStr(expr_)
{
	Parse();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RPN::SetExpression(string expr_)
{
	thatExprStr = expr_;
	Parse();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RPN::Parse()
{
	string expr = thatExprStr;
	vector<pair<size_t, AnyWithType>> places;
	vector<size_t> tmp;

	/*Find all places of operations*/
	for ( auto& e : thatOperAlphabet )
	{
		tmp = STR::FindInStrAll(thatExprStr, e.first);
		for ( auto& t : tmp ) places.push_back({ t, e.second });
	}
	
	/*sort to parse in right order and remove collisions*/
	sort(places.begin(), places.end(),
		[](pair<size_t, AnyWithType> a, pair<size_t, AnyWithType> b){ return a.first < b.first; });
	RemoveCollisions(&places);
	TestPrint(places);///

	ParseExpr(places);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RPN::RemoveCollisions(vector<pair<size_t, AnyWithType>>* v_)
{
	if ( v_->empty() ) return;

	unsigned i = 0;
	while ( i < v_->size()-1 )
	{
		/*if positions of found operations are the same*/
		if ( v_->operator[](i).first == v_->operator[](i + 1).first )
		{
			string s1 = GetSymbol(v_->operator[](i).second);
			string s2 = GetSymbol(v_->operator[](i + 1).second);
			if ( s1.empty() || s2.empty() )
			{
				cout << "\nRPN::RemoveCollisions error 2";
				system("pause");
			}
			/*if symbol of first is shorter than of next*/
			if ( s1.length() < s2.length() )
			{
				v_->erase(v_->begin() + i);
				continue;//do not increase i
			}
			else if ( s1.length() > s2.length() )
			{
				v_->erase(v_->begin() + i + 1);
				continue;//do not increase i
			}
			else
			{
				cout << "\nERROR in RevPolNotation::RemoveCollisions";
				system("pause");
			}
		}
		++i;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RPN::ParseExpr(std::vector<std::pair<size_t, AnyWithType>> v_)
{
	stack<AnyWithType> tmp_sta;
	string tmp_str;
	/*do the first oper*/
	if ( v_[0].first == 0 ) tmp_sta.push(v_[0].second);
	else
	{
		tmp_str = STR::SubStrFromTo(thatExprStr, 0, v_[0].first);
		tmp_str = STR::ReplaceInStrAll(tmp_str, " ", "");
		if ( !tmp_str.empty() ) thatExpr.push_back(AnyWithType(tmp_str, "string"));
		tmp_sta.push(v_[0].second);
	}

	/*finish rest of opers*/
	for ( unsigned i = 1; i < v_.size(); ++i )
	{
		if ( v_[i].second.TypeS() == "LogicOperations" )
		{
			auto tmp_oper = boost::any_cast<LogicOperations>(v_[i - 1].second.Data());
			tmp_str = STR::SubStrFromTo(thatExprStr, v_[i - 1].first + tmp_oper.Symbol().length(), v_[i].first);
			tmp_str = STR::ReplaceInStrAll(tmp_str, " ", "");
			if ( !tmp_str.empty() ) thatExpr.push_back(AnyWithType(tmp_str, "string"));
		
			ParseExprLogic(v_[i].second, tmp_sta);
		}
		else
		{
			cout << "\nRPN::ParseExpr MathOperations Not Done!(" << v_[i].second.TypeS() << ")";
			system("pause");
		}
	}

	/*extract value after last oper*/
	if ( v_.back().second.TypeS() == "LogicOperations" )
	{
		auto tmp_oper = boost::any_cast<LogicOperations>(v_.back().second.Data());
		tmp_str = STR::SubStrFromTo(thatExprStr, v_.back().first + tmp_oper.Symbol().length(), string::npos);
	}
	else
	{
		cout << "\nRPN::ParseExpr 2 MathOperations Not Done!(" << v_.back().second.TypeS() << ")";
		system("pause");
	}
	tmp_str = STR::ReplaceInStrAll(tmp_str, " ", "");
	if ( !tmp_str.empty() ) thatExpr.push_back(AnyWithType(tmp_str, "string"));

	/*extract all opers from tmp_que*/
	while ( !tmp_sta.empty() )
	{
		thatExpr.push_back(tmp_sta.top());
		tmp_sta.pop();
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RPN::ParseExprLogic(AnyWithType cur_oper_, stack<AnyWithType>& sta_)
{
	/* if que is empty - just push operation*/
	if ( sta_.empty() ) { sta_.push(cur_oper_); return; }
	LogicOperations tmp_oper_1;
	LogicOperations tmp_oper_2 = boost::any_cast<LogicOperations>(cur_oper_.Data());

	/* if operation is "(" just push in que*/
	if ( tmp_oper_2.Symbol() == "(" )
	{ 
		sta_.push(cur_oper_);
		return;
	}

	/*if oper if ")" then extract all opers from que until oper "("*/
	if ( tmp_oper_2.Symbol() == ")" )
	{
		while ( 1 )
		{
			tmp_oper_1 = boost::any_cast<LogicOperations>(sta_.top().Data());
			if ( tmp_oper_1.Symbol() != "(" )
			{
				thatExpr.push_back(sta_.top());
				sta_.pop();
			}
			else
			{
				sta_.pop();
				break;
			}
		}
		return;
	}

	/*check priority*/
	tmp_oper_1 = boost::any_cast<LogicOperations>(sta_.top().Data());

	/*if priority in que is less than current, then push in que*/
	if ( tmp_oper_1.Priority() < tmp_oper_2.Priority() ) 
	{ 
		sta_.push(cur_oper_);
		return; 
	}
	else
	{
		while ( 1 )
		{
			/*extract opers until que top priority is less than current*/
			tmp_oper_1 = boost::any_cast<LogicOperations>(sta_.top().Data());
			if ( tmp_oper_1.Priority() >= tmp_oper_2.Priority() )
			{
				thatExpr.push_back(sta_.top());
				sta_.pop();
			}
			else
			{
				sta_.push(cur_oper_);
				break;
			}

			/*if que empty - just push*/
			if ( sta_.empty() )
			{
				sta_.push(cur_oper_);
				break;
			}
		}
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string RPN::GetSymbol(AnyWithType a_)
{
	if ( a_.TypeS() == "LogicOperations" ) return boost::any_cast<LogicOperations>(a_.Data()).Symbol();
	else if ( a_.TypeS() == "MathOperations" ) return boost::any_cast<MathOperations>(a_.Data()).Symbol();
	else return "";
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RPN::SetOperationAlphabet(map<string, AnyWithType> oper_alphabet_, unsigned mode_)
{
	switch ( mode_ )
	{
		case Add: for ( auto& e : oper_alphabet_ ) thatOperAlphabet.insert(e); break;
		case Replace: thatOperAlphabet = oper_alphabet_; break;
		case Remove: 
			for ( auto& e : oper_alphabet_ )
			{
				auto it = thatOperAlphabet.find(e.first);
				if ( it != thatOperAlphabet.end() )
					thatOperAlphabet.erase(it);
			}
			break;
		default:
			cout << "\nRPN::SetOperationAlphabet error";
			system("pause");
			break;
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RPN::Init()
{
	thatOperAlphabet.insert({ "==",       AnyWithType(LogicOperations("=="),       "LogicOperations") });
	thatOperAlphabet.insert({ "!=",       AnyWithType(LogicOperations("!="),       "LogicOperations") });
	thatOperAlphabet.insert({ ">=",       AnyWithType(LogicOperations(">="),       "LogicOperations") });
	thatOperAlphabet.insert({ "<=",       AnyWithType(LogicOperations("<="),       "LogicOperations") });
	thatOperAlphabet.insert({ "<",        AnyWithType(LogicOperations("<"),        "LogicOperations") });
	thatOperAlphabet.insert({ ">",        AnyWithType(LogicOperations(">"),        "LogicOperations") });
	thatOperAlphabet.insert({ "&&",       AnyWithType(LogicOperations("&&"),       "LogicOperations") });
	thatOperAlphabet.insert({ "||",       AnyWithType(LogicOperations("||"),       "LogicOperations") });
	thatOperAlphabet.insert({ "^^",       AnyWithType(LogicOperations("^^"),       "LogicOperations") });
	thatOperAlphabet.insert({ "!",        AnyWithType(LogicOperations("!"),        "LogicOperations") });
	thatOperAlphabet.insert({ "contains", AnyWithType(LogicOperations("contains"), "LogicOperations") });
	thatOperAlphabet.insert({ "(",        AnyWithType(LogicOperations("("),        "LogicOperations") });
	thatOperAlphabet.insert({ ")",        AnyWithType(LogicOperations(")"),        "LogicOperations") });
	//thatOperAlphabet.insert({ "in",       AnyWithType(LogicOperations("in"),       "LogicOperations") });
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


