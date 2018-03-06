#pragma once
#include "stdafx.h"
template <class _T>
class qwe
{
private:

	_T thatData;

public:
	void Set(_T val_) ;
	_T Get() ;
	qwe() {}
	~qwe() {}
};

template<class _T> void qwe<_T>::Set(_T val_)
{
	thatData = val_;
}

template<class _T> _T qwe<_T>::Get()
{
	return thatData;
}