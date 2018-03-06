// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;
typedef boost::asio::io_service IO;
typedef boost::asio::io_service::work Work;

class C
{
private:

	map<string, string> f;
public:

	void Set(string name, string val) { f[name] = val; }
	string Get(string name) { return f[name]; }
	
};


int main()
{
	int exit;
	map<string, string> m;
	for ( auto& e : m )
	{
		m.begin();
	}
	C c;
	for ( auto& e : c )
	{

	}
	//string s = boost::to_string(std::this_thread::get_id()/*.hash()*/);
	//cout << "\nhash=" << s;
	//cout << "\nid=" << std::this_thread::get_id();
	//C c;
	///c.init();
	//c.doit();
	
	cin >> exit;
	return 0;
}

