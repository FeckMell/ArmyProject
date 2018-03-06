#include "stdafx.h"
#include "UDPSocketBuf.h"
using namespace std;

UDPSocketBuf::UDPSocketBuf()
{
	thatSize = 0;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
UDPSocketBuf::UDPSocketBuf(uint8_t* data_, size_t size_)
{
	if (size_ == 0 || data_ == nullptr) return;
	else if (size_ > 8000) return;
	
	memcpy(thatData, data_, size_);// �������� ��� data_ ������ size_
	thatSize = size_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
UDPSocketBuf::UDPSocketBuf(char* data_, size_t size_)
{
	if (size_ == 0 || data_ == nullptr) return;
	else if (size_ > 8000) return;

	memcpy(thatData, data_, size_);// �������� ��� data_ ������ size_
	thatSize = size_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
UDPSocketBuf::UDPSocketBuf(string& data_)
{
	if (data_ == "") return;
	else if (data_.length() > 8000) return;

	memcpy(thatData, data_.c_str(), data_.length());
	thatSize = data_.length();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
UDPSocketBuf::~UDPSocketBuf()
{
	thatSize = 0;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
int UDPSocketBuf::Add(uint8_t* data_, size_t size_)
{
	if (size_ < 1) return -1;
	else if (size_ > 8000) return -2;
	else if (size_ + thatSize > 8000) return -3;
	else if (data_ == nullptr) return -4;

	memcpy(thatData + thatSize, data_, size_);
	thatSize += size_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
int UDPSocketBuf::Add(char* data_, size_t size_)
{
	if (size_ < 1) return -1;
	else if (size_ > 8000) return -2;
	else if (size_ + thatSize > 8000) return -3;
	else if (data_ == nullptr) return -4;

	memcpy(thatData + thatSize, data_, size_);
	thatSize += size_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
int UDPSocketBuf::Add(std::string& data_)
{
	if (data_ == "") return -1;
	else if (data_.length() > 8000) return -2;
	else if (data_.length() + thatSize > 8000) return -3;

	memcpy(thatData + thatSize, data_.c_str(), data_.length());
	thatSize += data_.length();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
int UDPSocketBuf::Add(UDPSocketBuf& buf_)
{
	if (buf_.Size() == 0) return -1;
	else if (buf_.Size() > 8000) return -2;
	else if (buf_.Size() + thatSize > 8000) return -3;

	memcpy(thatData + thatSize, buf_.Data(), buf_.Size());
	thatSize += buf_.Size();
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
void UDPSocketBuf::Clear()
{
	thatData[0] = 0;
	thatSize = 0;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
uint8_t* UDPSocketBuf::Data()
{
	return thatData;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
size_t UDPSocketBuf::Size()
{
	return thatSize;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
int UDPSocketBuf::SetSize(size_t size_)
{
	if (size_ > 8000) return -1;
	if (size_ < 1) return -2;
	if (thatSize + size_ > 8000) return -3;
	thatSize += size_;
}
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------
//*///------------------------------------------------------------------------------------------