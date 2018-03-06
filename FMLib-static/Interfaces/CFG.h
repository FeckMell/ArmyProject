#pragma once
#include "stdafx.h"
#include "CommonTypes\Except.h"
#include "CommonTypes\DataStorage\ValStoreLineT.h"

class CFG
{
private:

	CFG() {}
	~CFG() {}

	static void ProcessPath(std::string path_, string filename_);
	static void ParseFile(std::string filename_);

	static ValStoreLineT<std::string> thatData;

public:	

	static std::pair<std::string, std::string> CutPathFromName(std::string str_);
	static std::string ToString();
	
	static void SetValFromFile(std::string path_, std::string filename_ = "fm.cfg");
	static void SetVal(std::string node_name_, std::map<std::string, std::string> data_);
	static void SetVal(std::string node_name_, ValStoreLineT<std::string> data_);
	static void SetVal(std::string name_, std::string value_);

	static std::string Val(std::string name_);
	static ValStoreLineT<std::string> ValSubTree(std::string name_);


};

