// Tests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;
typedef boost::asio::io_service IO;
typedef boost::asio::io_service::work Work;

#include "qwe.h"
/*struct A
{
	void ToString() {  }
};

struct B
{
	void tostring() {}
	string ToString() { return ""; }
};


template<class T> struct Test
{
	typedef void(T::*P)(void);

	typedef char False;
	template<class U, P = &U::ToString> struct True { char dummy[2]; };

	static False detect(...);
	template<class U> static True<U> detect(U*);

	static const bool exists = (sizeof(False) != sizeof(detect(static_cast<T*>(0))));
};


template<class T, bool b = Test<T>::exists> struct Foo;

template<class T> struct Foo<T, true>
{
	static void foo(const T &t) { cout << "Exists"; }
};

template<class T> struct Foo<T, false>
{
	static void foo(const T &t) { cout << "Nothing"; }
};
*/
int main()
{
	int exit;
	/*A a;	B b;cout << "\nA - "; Foo<A>::foo(a);cout << "\nB - "; Foo<B>::foo(b);*/

	deque<int> q;

	
	cin >> exit;
	return 0;
}

