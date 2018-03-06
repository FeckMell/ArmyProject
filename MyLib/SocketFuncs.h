#pragma once
#include "stdafx.h"
#include "Str.h"

class SocketFuncs
{
public:

	typedef boost::asio::io_service IO;
	typedef boost::asio::ip::udp::endpoint EP;
	typedef std::shared_ptr<boost::asio::io_service> SHP_IO;

	static bool IsIP(std::string ip_);
	static bool IsPort(std::string port_);
	static bool IsPort(int port_);

	static EP GetEP(std::string ip_, std::string port_);
	static EP GetEP(std::string ip_, int port_);

	static EP GetMyIP();//TODO
	static EP ResolveIP(std::string url_);//TODO
	static EP ResolveIP(std::string ip_, std::string port_);//TODO
	static EP ResolveIP(std::string ip_, int port_);//TODO

private:

	SocketFuncs();
	~SocketFuncs();

};