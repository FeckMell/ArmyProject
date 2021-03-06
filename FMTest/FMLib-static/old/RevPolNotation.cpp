#include "stdafx.h"
#include "RevPolNotation_old.h"

using namespace std;

map<string, AnyWithType> RevPolNotation::thatOperAlphabet = {};

void RevPolNotation::TestPrint(vector<pair<size_t, AnyWithType>> v)
{
	cout << "\n\nPOSITION OF OPERATIONS";
	for ( auto& e : v )
	{
		cout << "\nPosition=_" << e.first << "_ symbol=_" << GetSymbol(e.second) << "_";
	}
}
void RevPolNotation::TestPrint2()
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
			cout << "_" << boost::any_cast<Operation*>(e.Data())->Symbol() << "_";
		}
		else
		{
			cout << "\n PROBLEM!";
		}
	}
}

RevPolNotation::RevPolNotation(string expr_) :thatExprStr(expr_)
{
	Parse();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RevPolNotation::SetExpression(string expr_)
{
	thatExprStr = expr_;
	Parse();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
AnyWithType RevPolNotation::Evulate(boost::function<AnyWithType(string)> get_)
{
	deque<AnyWithType> expr = thatExpr;
	stack<AnyWithType> tmp_sta;
	AnyWithType tmp_v;

	while ( !expr.empty() )
	{
		tmp_v = expr.front();
		if ( tmp_v.TypeU() == AnyWithType::STRING )
		{
			//
		}
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RevPolNotation::Parse()
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
	auto a = [](pair<size_t, AnyWithType> a, pair<size_t, AnyWithType> b){ return a.first < b.first; };
	sort(places.begin(), places.end(),
		[](pair<size_t, AnyWithType> a, pair<size_t, AnyWithType> b){ return a.first < b.first; });
	RemoveCollisions(&places);
	//TestPrint(places);///

	ParseExpr(places);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RevPolNotation::RemoveCollisions(vector<pair<size_t, AnyWithType>>* v_)
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
void RevPolNotation::ParseExpr(std::vector<std::pair<size_t, AnyWithType>> v_)
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
			auto tmp_oper = boost::any_cast<Operation*>(v_[i - 1].second.Data());
			tmp_str = STR::SubStrFromTo(thatExprStr, v_[i - 1].first + tmp_oper->Symbol().length(), v_[i].first);
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
		auto tmp_oper = boost::any_cast<Operation*>(v_.back().second.Data());
		tmp_str = STR::SubStrFromTo(thatExprStr, v_.back().first + tmp_oper->Symbol().length(), string::npos);
	}
	else
	{
		cout << "\nRPN::ParseExpr 2 MathOperations Not Done!(" << v_.back().second.TypeS() << ")";
		system("pause");
	}
	tmp_str = STR::ReplaceInStrAll(tmp_str, " ", "");
	if ( !tmp_str.empty() ) thatExpr.push_back(AnyWithType(tmp_str, "string"));

	/*extract all opers from tmp_sta*/
	while ( !tmp_sta.empty() )
	{
		thatExpr.push_back(tmp_sta.top());
		tmp_sta.pop();
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RevPolNotation::ParseExprLogic(AnyWithType cur_oper_, stack<AnyWithType>& sta_)
{
	/* if stack is empty - just push operation*/
	if ( sta_.empty() ) { sta_.push(cur_oper_); return; }
	Operation* tmp_oper_1;
	Operation* tmp_oper_2 = boost::any_cast<Operation*>(cur_oper_.Data());

	/* if operation is "(" just push in stack*/
	if ( tmp_oper_2->Symbol() == "(" )
	{ 
		sta_.push(cur_oper_);
		return;
	}

	/*if oper if ")" then extract all opers from stack until oper "("*/
	if ( tmp_oper_2->Symbol() == ")" )
	{
		while ( 1 )
		{
			tmp_oper_1 = boost::any_cast<Operation*>(sta_.top().Data());
			if ( tmp_oper_1->Symbol() != "(" )
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
	tmp_oper_1 = boost::any_cast<Operation*>(sta_.top().Data());

	/*if priority in stack is less than current, then push in stack*/
	if ( tmp_oper_1->Priority() < tmp_oper_2->Priority() ) 
	{ 
		sta_.push(cur_oper_);
		return; 
	}
	else
	{
		while ( 1 )
		{
			/*extract opers until stack top priority is less than current*/
			tmp_oper_1 = boost::any_cast<Operation*>(sta_.top().Data());
			if ( tmp_oper_1->Priority() >= tmp_oper_2->Priority() )
			{
				thatExpr.push_back(sta_.top());
				sta_.pop();
			}
			else
			{
				sta_.push(cur_oper_);
				break;
			}

			/*if stack empty - just push*/
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
string RevPolNotation::GetSymbol(AnyWithType a_)
{
	if ( a_.TypeS() == "LogicOperations" ) return boost::any_cast<Operation*>(a_.Data())->Symbol();
	//else if ( a_.TypeS() == "MathOperations" ) return boost::any_cast<MathOperations>(a_.Data()).Symbol();
	else return "";
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void RevPolNotation::SetOperationAlphabet(map<string, AnyWithType> oper_alphabet_, unsigned mode_)
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
void RevPolNotation::Init()
{
	thatOperAlphabet.insert({ "==",       AnyWithType(Operation::Get("=="),       "LogicOperations") });
	thatOperAlphabet.insert({ "!=",       AnyWithType(Operation::Get("!="),       "LogicOperations") });
	thatOperAlphabet.insert({ ">=",       AnyWithType(Operation::Get(">="),       "LogicOperations") });
	thatOperAlphabet.insert({ "<=",       AnyWithType(Operation::Get("<="),       "LogicOperations") });
	thatOperAlphabet.insert({ "<",        AnyWithType(Operation::Get("<"),        "LogicOperations") });
	thatOperAlphabet.insert({ ">",        AnyWithType(Operation::Get(">"),        "LogicOperations") });
	thatOperAlphabet.insert({ "&&",       AnyWithType(Operation::Get("&&"),       "LogicOperations") });
	thatOperAlphabet.insert({ "||",       AnyWithType(Operation::Get("||"),       "LogicOperations") });
	thatOperAlphabet.insert({ "^^",       AnyWithType(Operation::Get("^^"),       "LogicOperations") });
	thatOperAlphabet.insert({ "!",        AnyWithType(Operation::Get("!"),        "LogicOperations") });
	thatOperAlphabet.insert({ "contains", AnyWithType(Operation::Get("contains"), "LogicOperations") });
	thatOperAlphabet.insert({ "(",        AnyWithType(Operation::Get("("),        "LogicOperations") });
	thatOperAlphabet.insert({ ")",        AnyWithType(Operation::Get(")"),        "LogicOperations") });
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


