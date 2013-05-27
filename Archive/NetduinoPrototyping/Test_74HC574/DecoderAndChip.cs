using System;
using Microsoft.SPOT;
using Microsoft.SPOT.Hardware;
using GHIElectronics.NETMF.FEZ;
using System.Threading;

namespace Test_74HC574
{
	class DecoderAndChip
	{
		OutputPort d0 = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di40, true);
		OutputPort d1 = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di41, false);
		OutputPort d2 = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di42, false);

		OutputPort[] outputs = new OutputPort[8];

		public void Run()
		{
			outputs[0] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di30, false);
			outputs[1] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di31, false);
			outputs[2] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di32, false);
			outputs[3] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di33, false);
			outputs[4] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di34, false);
			outputs[5] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di35, false);
			outputs[6] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di36, false);
			outputs[7] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di37, false);

			CopyToBuffer();

			DisableAll();

			Thread.Sleep(1000);

			while (true)
				for (int i = 0; i < 8; i++)
				{
					outputs[i].Write(true);
					CopyToBuffer();

					DisableAll();

					Thread.Sleep(100);
				}
		}

		void DisableAll()
		{
			for (int i = 0; i < 8; i++)
				outputs[i].Write(false);
		}

		void CopyToBuffer()
		{
			d0.Write(false);
			d0.Write(true);
		}
	}
}
