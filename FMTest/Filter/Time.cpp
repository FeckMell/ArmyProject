#include "stdafx.h"
#include "Time.h"
using namespace std;
std::string Time::thatTime;

void Time::StartWithTime(boost::function<void()> f_)
{
	auto begin = chrono::steady_clock::now();
	f_();
	auto end = chrono::steady_clock::now();

	auto H = chrono::duration_cast<chrono::hours>(end - begin);
	auto M = chrono::duration_cast<chrono::minutes>(end - begin) - H;
	auto S = chrono::duration_cast<chrono::seconds>(end - begin) - H - M;
	auto MS = chrono::duration_cast<chrono::milliseconds>(end - begin) - H - M - S;
	thatTime = "H:" + to_string(H.count()) + " M:" + to_string(M.count()) + " S:" + to_string(S.count()) + " MS:" + to_string(MS.count());
	cout << "H:" << H.count() << "\nM:" << M.count() << "\nS:" << S.count() << "\nMS:" << MS.count();
}