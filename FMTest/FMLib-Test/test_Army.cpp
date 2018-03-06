#include "stdafx.h"
#include "CppUnitTest.h"
#include "Tools\Tools.h"

#include "Parsers\Other\Army.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FMTest
{
	TEST_CLASS(test_Army)
	{
	public:

		//*///------------------------------------------------------------------------------------------
		//*///------------------------------------------------------------------------------------------
		TEST_METHOD(Constructor)
		{
			string s ="NetReceiver: Port=10000\n"
"ModemHeaderPleyada: FrameType=TDMA Time=2352842702 ModCod=0 Chan=0\n"
"iDirectRev: FreqId=1802 TerminalId=9 Prot=2048\n"
"IPv4: IpSrc=010.082.026.194 IpDst=054.243.127.065 Prot=6\n"
"IpSelector: Object=UNDEFINED\n"
"TCP: PortSrc=58251 PortDst=443 BeginTime=2017-06-28T11:14:05\n"
"Passport: File=\"Unk_TCP_PORTS/576/_010.082.026.194_054.243.127.065_006_58251_00443_010.082.026.194_elb084987-1848864735.us-east-1.elb.amazonaws.com_file1180244.bin\" Format=RAW Pos=0 Size=40";
			try
			{
				Army a(s);
			}
			catch (Except e)
			{
				Assert::IsFalse(true);
			}
			catch (...)
			{
				Assert::IsTrue(false);
			}
		}
	};
}