//#include "stdafx.h"
#include "Army.h"

using namespace std;

Army::Army(string& str_, string delimeter_) : thatRawData(str_), thatDelimeter(delimeter_)
{
	Parse();
	Analyze();

	thatDelimeter.clear();
	//thatRawData.clear();
	thatData.Clear();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void Army::Parse()
{
	/*Init*/
	vector<string> tmp_v;
	vector<string> lines;
	string name, par;
	string tmp_H;

	/*Split into lines for easier parsing*/
	lines = STR::StrToVec(thatRawData, thatDelimeter);
	for (unsigned i = 0; i < lines.size(); ++i)
	{
		/*Split line*/
		tmp_v = STR::StrToVec(lines[i], " ");

		/*Get root name*/
		tmp_H = STR::SubStrFromTo(tmp_v[0], 0, tmp_v[0].find(":"));

		/*Parse*/
		for (unsigned j = 1; j < tmp_v.size(); ++j)
		{
			name = STR::SubStrFromTo(tmp_v[j], 0, tmp_v[j].find("="));
			par = STR::SubStrFromTo(tmp_v[j], tmp_v[j].find("=") + 1, string::npos);
			if (name.empty() || par.empty()) continue;
			thatData.SetVal(tmp_H + "." + name, par);
		}
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void Army::Analyze()
{	
	try
	{
	vector<string> tmp;
	static vector<string> alphabetUNS = {
		"NetReceiver.Port", "ModemHeaderPleyada.Time", "ModemHeaderPleyada.ModCod", "ModemHeaderPleyada.Chan",
		"iDirectRev.FreqId", "iDirectRev.TerminalId", "iDirectRev.Prot", "IPv4.Prot", "TCP.PortSrc", "TCP.PortDst",
		"Passport.Pos", "Passport.Size", "DvbS2.Prot", "iDirect.Prot", "iDirect.Id", "UDP.PortSrc", "UDP.PortDst",
		"RTP.Ssrc", "GRE.Prot", "GRE.Ver" };
	
	tmp = thatData.NodesNamesAll();

	for (auto& e:tmp)
	{
		if (thatData.Val(e).empty()) continue;
		if (find(alphabetUNS.begin(), alphabetUNS.end(), e) != alphabetUNS.end())
			thatDataAny.SetVal(e, { STR::ToUnsigned_M(thatData.Val(e)), AnyWithType::UNSIGNED });
		else
			thatDataAny.SetVal(e, { thatData.Val(e), AnyWithType::STRING });
	}
	
		if (thatData.Val("Passport.File")[0] != '\"') throw	 Except("Bad data");
		if (thatData.Val("Passport.File").back() != '\"') throw	 Except("Bad data");
	}
	catch (Except e){ throw e; }
	
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
AnyWithType Army::Get(string name_)
{
	return thatDataAny.Val(name_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
std::string Army::GetRaw()
{
	return thatRawData;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------