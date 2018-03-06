#include "stdafx.h"
#include "SocketFuncs.h"
using namespace std;

SocketFuncs::SocketFuncs(){}
SocketFuncs::~SocketFuncs(){}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool SocketFuncs::IsIP(std::string ip_)
{
	vector<string> v = STR::StrToVec(ip_, ".");
	if (v.size() != 4) return false;
	int part;

	for (size_t i = 0; i < v.size(); ++i)
	{
		if (!STR::IsNumeric(v[i])) return false;
		part = stoi(v[i]);
		if (part < 0 || part > 255) return false;
	}
	return true;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool SocketFuncs::IsPort(std::string port_)
{
	if (!STR::IsNumeric(port_)) return false;
	int port = stoi(port_);
	if (port < 1 || port > 65535) return false;
	return true;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool SocketFuncs::IsPort(int port_)
{
	if (port_ < 1 || port_ > 65535) return false;
	return true;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
boost::asio::ip::udp::endpoint SocketFuncs::GetEP(std::string ip_, std::string port_)
{
	if (!(IsIP(ip_) || IsPort(port_))) return EP();
	else return EP(boost::asio::ip::address::from_string(ip_), stoi(port_));
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
boost::asio::ip::udp::endpoint SocketFuncs::GetEP(std::string ip_, int port_)
{
	if (!(IsIP(ip_) || IsPort(port_))) return EP();
	else return EP(boost::asio::ip::address::from_string(ip_), port_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------