// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

using namespace std;
typedef boost::asio::io_service IO;
typedef boost::asio::io_service::work Work;

class T
{
public:

	static T* Set(int s_) 
	{ 
		static T* statT = new T(s_);
		return statT;
	}
	int Get() { return a; }


private:

	int a;

	 
	~T(){}
	T() {}
	T(int a_) { a = a_; }
};

int main()
{
	int exit;
	
	T* t = T::Set(99);
	cout << t->Get();
	
	cin >> exit;
	return 0;
}

