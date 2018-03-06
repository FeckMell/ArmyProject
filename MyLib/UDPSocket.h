#pragma once
#include "stdafx.h"
#include "UDPSocketBuf.h"
#include "SocketFuncs.h"
#include "Str.h"

class UDPSocket
{
public:
	typedef boost::asio::io_service IO;
	typedef boost::asio::ip::udp::endpoint EP;
	typedef std::shared_ptr<boost::asio::io_service> SHP_IO;
	typedef std::shared_ptr<std::thread> SHP_thread;
	typedef boost::system::error_code error_code;
	typedef boost::asio::ip::udp::socket udpsocket;

	UDPSocket(SHP_IO io_, std::string server_ip_, std::string server_port_, std::string client_ip_ = "", std::string client_port_ = "");
	UDPSocket(SHP_IO io_, std::string server_ip_, int server_port_, std::string client_ip_ = "", int client_port_ = -1);
	~UDPSocket();

	bool IsOpened();
	SHP_UDPSocketBuf Data();

	void ChangeIO(SHP_IO new_io_);

	void AsyncReceiveFrom(boost::function<void()> func_, SHP_UDPSocketBuf buf_ = nullptr);
	void AsyncReceive(boost::function<void()> func_, SHP_UDPSocketBuf buf_ = nullptr);

	void ReceiveFrom(SHP_UDPSocketBuf buf_ = nullptr);
	void Receive(SHP_UDPSocketBuf buf_ = nullptr);

	void AsyncSendTo(boost::function<void()> func_, SHP_UDPSocketBuf data_);//TODO
	void SendTo(SHP_UDPSocketBuf data_);

	void SetEndPoint(std::string client_ip_, std::string client_port_);
	void SetEndPoint(std::string client_ip_, int client_port_);
	
private:

	void ReceiveHandle(error_code ec_, size_t size_, boost::function<void()> func_, SHP_UDPSocketBuf buf_);
	void SendHandle(error_code ec_, size_t size_, boost::function<void()> func_, SHP_UDPSocketBuf buf_);

	EP thatEndpoint;
	SHP_IO thatIO;
	udpsocket thatSocket;
	SHP_UDPSocketBuf thatBuffer;
	bool opened = false;

};