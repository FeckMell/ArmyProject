#pragma once
#include "stdafx.h"
#include "Except.h"
#include "Operation.h"

class Evulation
{
public:

	template<class T_, class R_> static bool UseB(const T_& a_, const R_& b_, Operation* op_);
	//template<class T_, class R_> static double UseD(T_ a_, R_ b_, Operation* op_);

private:

	Evulation(){}
	~Evulation(){}
};

template<class T_, class R_> static bool Evulation::UseB(const T_& a_, const R_& b_, Operation* op_)
{
	try
	{
		switch ( op_->Id() )
		{
			case Operation::EQ: return Operation::EQ::Use(a_, b_);
			case Operation::NEQ: return Operation::NEQ::Use(a_, b_);
			case Operation::GE: return Operation::GE::Use(a_, b_);
			case Operation::LE: return Operation::LE::Use(a_, b_);
			case Operation::G: return Operation::G::Use(a_, b_);
			case Operation::L: return Operation::L::Use(a_, b_);
			case Operation::AND: return Operation::AND::Use(a_, b_);
			case Operation::OR: return Operation::OR::Use(a_, b_);
			case Operation::CONTAINS: return Operation::CONTAINS::Use(a_, b_);
			//case typeid(Operation::NOT) : return Operation::NOT::Use(a_, b_);
			default: throw Except("Bad Operation id\nid=" + std::to_string(op_->Id()));
		}
	}
	catch ( Except& e_ )
	{
		if ( e_.What().find("Bad Operation id\nid=") != std::string::npos )
			e_.Push("Evulation::UseB bad operation.");
		throw e_;
	}
}