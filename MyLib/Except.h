#pragma once
#include "stdafx.h"

class Except
{
private:

	std::stack<std::string> thatData;

public:

	std::string What();
	std::string Pop();
	void Push(std::string what_);
	bool Empty();

	Except(std::string what_);
	//Except() {}
	~Except() {}
};

