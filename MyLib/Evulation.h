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

	Evulation();
	~Evulation();
};

template<class T_, class R_> static bool Evulation::UseB(const T_& a_, const R_& b_, Operation* op_)
{
	try
	{
		switch ( op_->Id() )
		{
			case typeid(Operation::EQ) : return Operation::EQ::Use(a_, b_);
			case typeid(Operation::NEQ) : return Operation::NEQ::Use(a_, b_);
			case typeid(Operation::GE) : return Operation::GE::Use(a_, b_);
			case typeid(Operation::LE) : return Operation::LE::Use(a_, b_);
			case typeid(Operation::G) : return Operation::G::Use(a_, b_);
			case typeid(Operation::L) : return Operation::L::Use(a_, b_);
			case typeid(Operation::AND) : return Operation::AND::Use(a_, b_);
			case typeid(Operation::OR) : return Operation::OR::Use(a_, b_);
			case typeid(Operation::CONTAINS) : return Operation::CONTAINS::Use(a_, b_);
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