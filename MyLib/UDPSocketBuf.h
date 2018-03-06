#pragma once
#include "stdafx.h"

class UDPSocketBuf
{
public:

	UDPSocketBuf();
	UDPSocketBuf(uint8_t* data_, size_t size_);
	UDPSocketBuf(char* data_, size_t size_);
	UDPSocketBuf(std::string& data_);

	~UDPSocketBuf();

	int Add(uint8_t* data_, size_t size_);
	int Add(char* data_, size_t size_);
	int Add(std::string& data);
	int Add(UDPSocketBuf& buf_);

	int SetSize(size_t size_);
	void Clear();
	uint8_t* Data();
	size_t Size();

private:
	
	uint8_t thatData[8000];
	size_t thatSize = 0;

}; typedef std::shared_ptr<UDPSocketBuf> SHP_UDPSocketBuf;