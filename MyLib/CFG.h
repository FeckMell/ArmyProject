#pragma once
#include "stdafx.h"
#include "ValStoreLine.h"

class CFG
{
private:

	typedef std::string string;

	CFG() {}
	~CFG() {}

	static void ParseExtra();
	static void ParsePath();
	static void Parse();

	static ValStoreLine thatData;

public:

	static void Init(string path_);
	static void InitWithDefaults(string path_, std::map<string, string> defaults_);
	static string Val(string name_);
	static void SetVal(string name_, string value_);
	static void SetVal(std::map<std::string, string> data_);
	static string ToString();

};

