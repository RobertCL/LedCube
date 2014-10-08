#include "Energia.h"
#include "HC138N.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

HC138N::HC138N(long port):_port(port){}

HC138N::~HC138N(){}

void HC138N::init(){
   	GPIOPinTypeGPIOOutput(_port, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 );
	GPIOPinWrite(_port, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x00);
	disable();
}

void HC138N::setp(unsigned char value){
	set(value);
	pulse();
}

void HC138N::set(unsigned char value) {
	GPIOPinWrite(_port, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2, value);
}

void HC138N::enable(){
	GPIOPinWrite(_port, GPIO_PIN_3, 0xFF);
}

void HC138N::disable(){
	GPIOPinWrite(_port, GPIO_PIN_3, 0x00);
}

void HC138N::pulse() {
	enable();
	disable();
}
