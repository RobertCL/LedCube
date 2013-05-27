using GHIElectronics.NETMF.FEZ;
using Microsoft.SPOT.Hardware;

namespace Test_74HC574
{
	class HC138N
	{
		static readonly OutputPort enable = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di43, false);
		static readonly OutputPort in0 = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di40, false);
		static readonly OutputPort in1 = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di41, false);
		static readonly OutputPort in2 = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di42, false);

		/// <summary>
		/// Set the inputs of the HC138N
		/// </summary>
		/// <param name="pos">Should be in the range 0-7</param>
		public HC138N Set(byte pos)
		{
			var d0state = (pos & 0x01) == 0x01;
			in0.Write(d0state);
			var d1state = (pos & 0x02) == 0x02;
			in1.Write(d1state);
			var d2state = (pos & 0x04) == 0x04;
			in2.Write(d2state);

			return this;
		}

		/// <summary>
		/// Toggle the output of the HC138N on then off
		/// </summary>
		public void Pulse()
		{
			enable.Write(true);
			enable.Write(false);
		}
	}
}
