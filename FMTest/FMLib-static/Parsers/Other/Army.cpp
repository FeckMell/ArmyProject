#include "stdafx.h"
#include "Army.h"

using namespace std;

Army::Army(string str_, string delimeter_) : thatRawData(str_), thatDelimeter(delimeter_)
{
	Parse();
	Check();
	Analyze();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
string Army::Val(string name_)
{
	return thatData.Val(name_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void Army::Parse()
{
	/*Init*/
	vector<string> lines;
	size_t fd_begin;
	size_t fd_end;
	vector<vector<string>> alphabet=
	{
		{ "NetReceiver", "Port","$"},
		{ "ModemHeaderPleyada", "FrameType", "Time", "ModCod", "Chan", "$" },
		{ "iDirectRev", "FreqId", "TerminalId", "Prot", "$" },
		{ "IPv4", "IpSrc", "IpDst", "Prot", "$" },
		{ "IpSelector", "Object", "$" },
		{ "TCP", "PortSrc", "PortDst", "BeginTime", "$" },
		{ "Passport", "File", "Format", "Pos", "Size", "$" }
	};

	/*Split into lines for easier parsing*/
	lines = STR::StrToVec(thatRawData, thatDelimeter);
	for (unsigned i = 0; i < lines.size(); ++i)
	{
		lines[i]+=" $";
		for (unsigned j = 1; j < alphabet[i].size() - 1; ++j)
		{
			fd_begin = lines[i].find(alphabet[i][j] + "=") + 1 + alphabet[i][j].length(); /* +1 symbol "="*/
			fd_end = lines[i].find(alphabet[i][j + 1]) - 1; /*clear " "*/
			thatData.SetVal(alphabet[i][0] + "." + alphabet[i][j], STR::SubStrFromTo(lines[i], fd_begin, fd_end));
		}
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void Army::Check()
{
	/*Init check for data persistance*/
	vector<string> alphabet = { 
		"IPv4.IpDst", "IPv4.IpSrc", "IPv4.Prot", "IpSelector.Object", "ModemHeaderPleyada.Chan",
		"ModemHeaderPleyada.FrameType", "ModemHeaderPleyada.ModCod", "ModemHeaderPleyada.Time",
		"NetReceiver.Port", "Passport.File", "Passport.Format", "Passport.Pos", "Passport.Size",
		"TCP.BeginTime", "TCP.PortDst", "TCP.PortSrc", "iDirectRev.FreqId", "iDirectRev.Prot", "iDirectRev.TerminalId" };

	for (auto& e : alphabet) if (thatData.Val(e).empty()) throw Except("Bad data");
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void Army::Analyze()
{	
	try
	{
		/*Numeric Data Check*/
		vector<string> alphabet = { 
			"NetReceiver.Port", "ModemHeaderPleyada.Time", "ModemHeaderPleyada.ModCod", "ModemHeaderPleyada.Chan", 
			"iDirectRev.FreqId", "iDirectRev.TerminalId", "iDirectRev.Prot", "IPv4.Prot", "TCP.PortSrc", "TCP.PortDst", 
			"Passport.Pos", "Passport.Size" };
		for (auto& e : alphabet) 
			thatDataAny.SetVal(e, { STR::ToUnsigned_M(thatData.Val(e)), AnyWithType::UNSIGNED });

		/*Other*/
		vector<string> tmp_s;
		unsigned tmp_u;

			/*Check IP source*/
		thatDataAny.SetVal("IPv4.IpSrc", { thatData.Val("IPv4.IpSrc"), AnyWithType::STRING });
		tmp_s = STR::StrToVec(thatData.Val("IPv4.IpSrc"), ".");
		for (unsigned i = 0; i < tmp_s.size(); ++i)
		{
			tmp_u = STR::ToUnsigned_M(tmp_s[i]);
			if (tmp_u > 255) throw Except("Bad data");
		}


			/*Check IP dest*/
		thatDataAny.SetVal("IPv4.IpDst", { thatData.Val("IPv4.IpDst"), AnyWithType::STRING });
		tmp_s = STR::StrToVec(thatData.Val("IPv4.IpDst"), ".");
		for (unsigned i = 0; i < tmp_s.size(); ++i)
		{
			tmp_u = STR::ToUnsigned_M(tmp_s[i]);
			if (tmp_u > 255) throw Except("Bad data");
		}

			/*Check Time*/
		regex e(R"((\d{4})-(\d{2})-(\d{2})T(\d{2}):(\d{2}):(\d{2}))");/*2017-06-28T11:14:05*/
		cmatch result;
		try{ regex_match(thatData.Val("TCP.BeginTime").c_str(), result, e); }
		catch (exception& e){ throw Except(e.what()); }
		if (result.size() != 7){ throw Except("Bad data"); }

			/*Check FileName*/
		thatDataAny.SetVal("Passport.File", { thatData.Val("Passport.File"), AnyWithType::STRING });
		if (thatData.Val("Passport.File")[0] != '\"') throw	 Except("Bad data");
		if (thatData.Val("Passport.File").back() != '\"') throw	 Except("Bad data");
	}
	catch (Except e){ throw e; }
	thatDataAny.SetVal("IpSelector.Object", { thatData.Val("IpSelector.Object"), AnyWithType::STRING });
	thatDataAny.SetVal("ModemHeaderPleyada.FrameType", { thatData.Val("ModemHeaderPleyada.FrameType"), AnyWithType::STRING });
	thatDataAny.SetVal("Passport.Format", { thatData.Val("Passport.Format"), AnyWithType::STRING });
	thatDataAny.SetVal("TCP.BeginTime", { thatData.Val("TCP.BeginTime"), AnyWithType::STRING });
	
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
AnyWithType Army::Get(string name_)
{
	return thatDataAny.Val(name_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------