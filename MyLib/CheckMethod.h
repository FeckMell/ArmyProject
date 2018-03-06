#pragma once
#include "stdafx.h"

#undef Test_Method
#ifdef Test_Method

struct Test_A
{
	void ToString() {}
};

struct Test_B
{
	void tostring() {}
	std::string ToString() { return ""; }
};


template<class T> struct Test_TestMethod
{
	typedef void(T::*P)(void);

	typedef char False;
	template<class U, P = &U::ToString> struct True { char dummy[2]; };

	static False detect(...);
	template<class U> static True<U> detect(U*);

	static const bool exists = (sizeof(False) != sizeof(detect(static_cast<T*>(0))));
};


template<class T, bool b = Test_TestMethod<T>::exists> struct Test_Foo;

template<class T> struct Test_Foo<T, true>
{
	static void foo(const T &t) { cout << "Exists"; }
};

template<class T> struct Test_Foo<T, false>
{
	static void foo(const T &t) { cout << "Nothing"; }
};

/*
int main()
{
	A a;
	B b;
	cout << "\nA - "; Test_Foo<A>::foo(a);
	cout << "\nB - "; Test_Foo<B>::foo(b);
}
*/
#endif