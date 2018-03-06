#pragma once
#include "stdafx.h"
#include "CommonTypes/DataStorage/ValStoreLineT.h"
#include "Interfaces/STR.h"

/*Except:
"Bad data"
*/
class Army
{
private:

	void Parse();
	void Check();
	void Analyze();

	std::string thatDelimeter;
	std::string thatRawData;
	ValStoreLineT<std::string> thatData;
	ValStoreLineT<AnyWithType> thatDataAny;

public:

	//enum { INT = AnyWithType::MaxType + 1, UNSIGNED, DOUBLE, BOOL, STRING };

	Army(){}
	~Army(){}
	
	Army(std::string str_, std::string delimeter_ = "\n");

	std::string Val(std::string name_);
	AnyWithType Get(std::string name_);

};

