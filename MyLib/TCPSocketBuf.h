#pragma once
#include "stdafx.h"

class TCPSocketBuf
{
public:

	TCPSocketBuf();
	TCPSocketBuf(uint8_t* data_, size_t size_);
	TCPSocketBuf(char* data_, size_t size_);
	TCPSocketBuf(std::string& data_);

	~TCPSocketBuf();

	int SetSize(size_t size_);
	int Add(uint8_t* data_, size_t size_);
	int Add(char* data_, size_t size_);
	int Add(std::string& data);
	int Add(TCPSocketBuf& buf_);

	void Clear();
	uint8_t* Data();
	size_t Size();

protected:

	size_t thatSize = 0;
	std::vector<uint8_t> thatData;

}; typedef std::shared_ptr<TCPSocketBuf> SHP_TCPSocketBuf;