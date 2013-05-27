#include "LayerControl.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

LayerControl::LayerControl(){
	// LayerControl
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);
	GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
	off();
}

LayerControl::~LayerControl(){}

void LayerControl::off(){
	// all off
	GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7, 0x00);
}

void LayerControl::on(int layer){

	off();

	switch(layer){

	case 0:
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0xFF);
		break;

	case 1:
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0xFF);
		break;

	case 2:
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0xFF);
		break;

	case 3:
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0xFF);
		break;

	case 4:
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0xFF);
		break;

	case 5:
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0xFF);
		break;

	case 6:
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0xFF);
		break;

	case 7:
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0xFF);
		break;
	}
}
