#pragma once
#include "stdafx.h"
#include <Calculation\Math\RevPolNotation.h>
#include <Parsers\Other\Army.h>
#include "Time.h"

class Process
{
public:

	static void Init(std::string filename_out_);

	static void Filter(RevPolNotation& rpn_, std::vector<Army>& data_);
	static void PrintFiltered(std::vector<Army>& data_, std::string filename_in_, std::string filter_);

private:

	static void WriteToFile(Army& a_);

	static std::string thatFilenameOut;
	static std::ofstream thatFile;
	static std::vector<unsigned> thatFiltered;
	static std::vector<unsigned> thatErrors;

	Process(){}
	~Process(){}
};

