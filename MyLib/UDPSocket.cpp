#include "stdafx.h"
#include "UDPSocket.h"
using namespace std;

UDPSocket::UDPSocket(SHP_IO io_, string server_ip_, string server_port_, string client_ip_, string client_port_) : thatSocket(*io_.get())
{
	EP ep = SocketFuncs::GetEP(server_ip_, server_port_);
	if (ep == EP()) return;
	thatSocket.open(boost::asio::ip::udp::v4());
	thatSocket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
	thatSocket.bind(ep);
	opened = true;

	if (client_ip_ != "" && client_port_ != "")
	{
		thatEndpoint = SocketFuncs::GetEP(client_ip_, client_port_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
UDPSocket::UDPSocket(SHP_IO io_, string server_ip_, int server_port_, string client_ip_, int client_port_) : thatSocket(*io_.get())
{
	EP ep = SocketFuncs::GetEP(server_ip_, server_port_);
	if (ep == EP()) return;
	thatSocket.open(boost::asio::ip::udp::v4());
	thatSocket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
	thatSocket.bind(ep);
	opened = true;

	if (SocketFuncs::IsIP(client_ip_) && SocketFuncs::IsPort(client_port_))
	{
		thatEndpoint = SocketFuncs::GetEP(client_ip_, client_port_);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
UDPSocket::~UDPSocket()
{
	opened = false;
	thatSocket.cancel();
	thatSocket.close();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
bool UDPSocket::IsOpened()
{
	return opened;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
SHP_UDPSocketBuf UDPSocket::Data()
{
	return thatBuffer;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::SetEndPoint(std::string client_ip_, std::string client_port_)
{
	thatEndpoint = SocketFuncs::GetEP(client_ip_, client_port_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::SetEndPoint(std::string client_ip_, int client_port_)
{
	thatEndpoint = SocketFuncs::GetEP(client_ip_, client_port_);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::AsyncReceiveFrom(boost::function<void()> func_, SHP_UDPSocketBuf buf_)
{
	if (buf_ == nullptr)
	{
		thatSocket.async_receive_from(
			boost::asio::buffer(thatBuffer->Data(), 8000),
			thatEndpoint,
			boost::bind(&UDPSocket::ReceiveHandle, this, _1, _2, func_, nullptr)
			);
	}
	else
	{
		thatSocket.async_receive_from(
			boost::asio::buffer(buf_->Data(), 8000),
			thatEndpoint,
			boost::bind(&UDPSocket::ReceiveHandle, this, _1, _2, func_, buf_)
			);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::AsyncReceive(boost::function<void()> func_, SHP_UDPSocketBuf buf_)
{
	if (buf_ == nullptr)
	{
		thatSocket.async_receive(
			boost::asio::buffer(thatBuffer->Data(), 8000),
			boost::bind(&UDPSocket::ReceiveHandle, this, _1, _2, func_, buf_)
			);
	}
	else
	{
		thatSocket.async_receive(
			boost::asio::buffer(buf_->Data(), 8000),
			boost::bind(&UDPSocket::ReceiveHandle, this, _1, _2, func_, buf_)
			);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::ReceiveFrom(SHP_UDPSocketBuf buf_)
{
	if (buf_ == nullptr)
	{
		size_t size = thatSocket.receive_from(
			boost::asio::buffer(thatBuffer->Data(), 8000),
			thatEndpoint
			);
		thatBuffer->SetSize(size);
	}
	else
	{
		size_t size = thatSocket.receive_from(
			boost::asio::buffer(buf_->Data(), 8000),
			thatEndpoint
			);
		buf_->SetSize(size);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::Receive(SHP_UDPSocketBuf buf_)
{
	if (buf_ == nullptr)
	{
		size_t size = thatSocket.receive(boost::asio::buffer(thatBuffer->Data(), 8000));
		thatBuffer->SetSize(size);
	}
	else
	{
		size_t size = thatSocket.receive(boost::asio::buffer(buf_->Data(), 8000));
		buf_->SetSize(size);
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::ReceiveHandle(error_code ec_, size_t size_, boost::function<void()> func_, SHP_UDPSocketBuf buf_)
{
	if (buf_ == nullptr)
	{
		thatBuffer->SetSize(size_);
		func_();
		/*thatSocket.async_receive_from(
			boost::asio::buffer(thatBuffer->Data(), 8000),
			thatEndpoint,
			boost::bind(&UDPSocket::ReceiveHandle, this, _1, _2, func_, nullptr)
			);*/
	}
	else
	{
		buf_->SetSize(size_);
		func_();
		/*thatSocket.async_receive_from(
			boost::asio::buffer(buf_->Data(), 8000),
			thatEndpoint,
			boost::bind(&UDPSocket::ReceiveHandle, this, _1, _2, func_, buf_)
			);*/
	}
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::AsyncSendTo(boost::function<void()> func_, SHP_UDPSocketBuf data_)
{
	if (data_ == nullptr) return;

	thatSocket.async_send_to(
		boost::asio::buffer(data_->Data(), data_->Size()),
		thatEndpoint,
		boost::bind(&UDPSocket::SendHandle, this, _1, _2, func_, data_)
		);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::SendTo(SHP_UDPSocketBuf data_)
{
	thatSocket.send_to(boost::asio::buffer(data_->Data(), data_->Size()), thatEndpoint);
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::SendHandle(error_code ec_, size_t size_, boost::function<void()> func_, SHP_UDPSocketBuf buf_)
{
	func_();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocket::ChangeIO(SHP_IO new_io_)
{
	if (new_io_ == nullptr) return;
	opened = false;

	EP ep = thatSocket.local_endpoint();
	thatSocket.cancel();
	thatSocket.close();
	thatSocket = udpsocket(*new_io_.get());

	thatSocket.open(boost::asio::ip::udp::v4());
	thatSocket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
	thatSocket.bind(ep);
	opened = true;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------