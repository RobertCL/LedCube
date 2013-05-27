using System;
using Microsoft.SPOT;
using GHIElectronics.NETMF.Hardware;
using System.Threading;

namespace Test_74HC574
{
	class LedResistorTest
	{
		public void Run()
		{
			var p = new PWM(PWM.Pin.PWM1);

			var freq = 60;
			byte duty = 12;

			p.Set(freq, duty);
		}
	}
}
