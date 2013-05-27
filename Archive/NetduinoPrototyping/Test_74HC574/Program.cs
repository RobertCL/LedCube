using System;
using System.Threading;

using Microsoft.SPOT;
using Microsoft.SPOT.Hardware;

using GHIElectronics.NETMF.FEZ;

namespace Test_74HC574
{
	public class Program
	{
		public static void Main()
		{
			//var prog = new ChipOnly();
			//var prog = new DecoderAndChip();

			//var prog2 = new LedResistorTest();
			var prog = new DecoderAndTwoChips();

			//var line1 = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di0, true);

			/*var t = new Thread(new ThreadStart(() => 
			{
				while (true)
				{
					line1.Write(true);
					Thread.Sleep(1);
					line1.Write(false);
					Thread.Sleep(1);
				}
			}));

			t.Start();*/

			//prog2.Run();
			prog.Run();
		}
	}
}
