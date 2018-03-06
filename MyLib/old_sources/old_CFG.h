#pragma once
#include "stdafx.h"
#include "Str.h"

class CFG
{
public:

	static void Init(std::string path_);
	static void InitWithDefaults(std::string path_, std::map<std::string, std::string> defaults_);//TODO
	static std::string Val(std::string name_);
	static void SetVal(std::string name_, std::string value_);
	static void SetVal(std::map<std::string, std::string> data_);
	static std::string ToStringAll();

private:

	static void ParseExtra();
	static void ParsePath();
	static void Parse();

	static std::map<std::string, std::string> thatDataMap;

};