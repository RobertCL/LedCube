using System;
using Microsoft.SPOT;
using Microsoft.SPOT.Hardware;
using GHIElectronics.NETMF.FEZ;
using System.Threading;

namespace Test_74HC574
{
	class DecoderAndTwoChips
	{
		static readonly OutputPort[] outputs = new OutputPort[8];
		static readonly HC138N shifter = new HC138N();
		static readonly LayerSelector layers = new LayerSelector();

		#region Programs

		static readonly byte[] program = new byte[]
			{
				255, 0, 0, 0, 0, 0, 0, 0,
				0, 255, 0, 0, 0, 0, 0, 0,
				0, 0, 255, 0, 0, 0, 0, 0,
				0, 0, 0, 255, 0, 0, 0, 0,
				0, 0, 0, 0, 255, 0, 0, 0,
				0, 0, 0, 0, 0, 255, 0, 0,
				0, 0, 0, 0, 0, 0, 255, 0,
				0, 0, 0, 0, 0, 0, 0, 255,
				0, 0, 0, 0, 0, 0, 255, 0,
				0, 0, 0, 0, 0, 255, 0, 0,
				0, 0, 0, 0, 255, 0, 0, 0,
				0, 0, 0, 255, 0, 0, 0, 0,
				0, 0, 255, 0, 0, 0, 0, 0,
				0, 255, 0, 0, 0, 0, 0, 0,

				
				1, 1, 1, 1, 1, 1, 1, 1,
				2, 2, 2, 2, 2, 2, 2, 2,
				4, 4, 4, 4, 4, 4, 4, 4,
				8, 8, 8, 8, 8, 8, 8, 8,
				16, 16, 16, 16, 16, 16, 16, 16,
				32, 32, 32, 32, 32, 32, 32, 32,
				64, 64, 64, 64, 64, 64, 64, 64,
				128, 128, 128, 128, 128, 128, 128, 128,
				64, 64, 64, 64, 64, 64, 64, 64,
				32, 32, 32, 32, 32, 32, 32, 32,
				16, 16, 16, 16, 16, 16, 16, 16,
				8, 8, 8, 8, 8, 8, 8, 8,
				4, 4, 4, 4, 4, 4, 4, 4,
				2, 2, 2, 2, 2, 2, 2, 2,
				1, 1, 1, 1, 1, 1, 1, 1,
			};

		static readonly byte[] program2 = new byte[]
		{
				255, 0, 0, 0, 0, 0, 0, 0,
				255, 255, 0, 0, 0, 0, 0, 0,
				255, 255, 255, 0, 0, 0, 0, 0,
				255, 255, 255, 255, 0, 0, 0, 0,
				255, 255, 255, 255, 255, 0, 0, 0,
				255, 255, 255, 255, 255, 255, 0, 0,
				255, 255, 255, 255, 255, 255, 255, 0,
				255, 255, 255, 255, 255, 255, 255, 255,
				255, 255, 255, 255, 255, 255, 255, 0,
				255, 255, 255, 255, 255, 255, 0, 0,
				255, 255, 255, 255, 255, 0, 0, 0,
				255, 255, 255, 255, 0, 0, 0, 0,
				255, 255, 255, 0, 0, 0, 0, 0,
				255, 255, 0, 0, 0, 0, 0, 0,

				
				1, 1, 1, 1, 1, 1, 1, 1,
				3, 3, 3, 3, 3, 3, 3, 3,
				7, 7, 7, 7, 7, 7, 7, 7,
				15, 15, 15, 15, 15, 15, 15, 15,
				31, 31, 31, 31, 31, 31, 31, 31,
				63, 63, 63, 63, 63, 63, 63, 63,
				127, 127, 127, 127, 127, 127, 127, 127,
				255, 255, 255, 255, 255, 255, 255, 255,
				127, 127, 127, 127, 127, 127, 127, 127,
				63, 63, 63, 63, 63, 63, 63, 63,
				31, 31, 31, 31, 31, 31, 31, 31,
				15, 15, 15, 15, 15, 15, 15, 15,
				7, 7, 7, 7, 7, 7, 7, 7,
				3, 3, 3, 3, 3, 3, 3, 3,
				1, 1, 1, 1, 1, 1, 1, 1,
		};

		static readonly byte[] program3 = new byte[]
		{
			255, 255, 255, 255, 255, 255, 255, 255
		};



		#endregion

		private void Init()
		{
			outputs[0] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di30, false);
			outputs[1] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di31, false);
			outputs[2] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di32, false);
			outputs[3] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di33, false);
			outputs[4] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di34, false);
			outputs[5] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di35, false);
			outputs[6] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di36, false);
			outputs[7] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di37, false);

			// Everything off, shift all out
			for (byte i = 0; i < 8; i++)
				shifter.Set(i).Pulse();
		}

		public void Run()
		{
			Init();

			/* Light up whole cube test (Panda too slow)
			while (true)
			{
				for (sbyte layer = 0; layer < 8; layer++)
				{
					for (byte j = 0; j < 8; j++)
					{
						Set8(255);
						shifter.Set(j).Pulse();
					}
					layers.Enable(layer);
				}
			}
			*/

			while (true)
			{
				for (sbyte layer = 0; layer < 8; layer++)
				{
					layers.Enable(layer);
					Run(program, 30);
				}

				for (sbyte layer = 0; layer < 8; layer++)
				{
					layers.Enable(layer);
					Run(program2, 30);
				}
			}
		}

		private void Run(byte[] program, int delay)
		{
			int i = 0;

			while (true)
			{
				for (byte j = 0; j < 8; j++)
				{
					Set8(program[i + j]);
					shifter.Set(j).Pulse();
				}

				Thread.Sleep(delay);

				i += 8; 
				
				if (i + 7 > program.Length) { break; }
			}
		}

		void Set8(byte state)
		{
			outputs[0].Write((state & 1) == 1);
			outputs[1].Write((state & 2) == 2);
			outputs[2].Write((state & 4) == 4);
			outputs[3].Write((state & 8) == 8);
			outputs[4].Write((state & 16) == 16);
			outputs[5].Write((state & 32) == 32);
			outputs[6].Write((state & 64) == 64);
			outputs[7].Write((state & 128) == 128);
		}

		void DisableAll()
		{
			for (byte i = 0; i < 8; i++)
				outputs[i].Write(false);
		}
	}
}

