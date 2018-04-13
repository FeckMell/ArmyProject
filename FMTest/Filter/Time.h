#pragma once
#include <Calculation\Math\RevPolNotation.h>
#include <Parsers\Other\Army.h>
#include "stdafx.h"

class Time
{

public:

	static void StartWithTime(boost::function<void()> f_);
	static std::string Get(){ return thatTime; }

private:

	static std::string thatTime;

	Time(){}
	~Time(){}

};

