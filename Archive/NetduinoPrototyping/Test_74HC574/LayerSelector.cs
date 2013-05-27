using GHIElectronics.NETMF.FEZ;
using Microsoft.SPOT.Hardware;

namespace Test_74HC574
{
	class LayerSelector
	{
		readonly OutputPort[] layers;
		sbyte currentlyEnabledLayer = -1;

		public LayerSelector()
		{
			layers = new OutputPort[8];
			layers[0] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di20, false);
			layers[1] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di21, false);
			layers[2] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di22, false);
			layers[3] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di23, false);
			layers[4] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di24, false);
			layers[5] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di25, false);
			layers[6] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di26, false);
			layers[7] = new OutputPort((Cpu.Pin)FEZ_Pin.Digital.Di27, false);
		}

		/// <summary>
		/// Enable a particular layer.
		/// </summary>
		/// <param name="layerIndex">Index of layer to enable - should be 0 to 7 or -1 to disable all</param>
		public void Enable(sbyte layerIndex)
		{
			if (currentlyEnabledLayer != -1)
				layers[currentlyEnabledLayer].Write(false);

			if (layerIndex != -1)
				layers[layerIndex].Write(true);

			currentlyEnabledLayer = layerIndex;
		}
	}
}
