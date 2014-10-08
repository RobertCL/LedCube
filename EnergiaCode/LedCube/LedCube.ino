#include "Energia.h"
#include "driverlib/sysctl.h"
#include "HC138N.h"
#include "LayerControl.h"
#include "Sequence.h"
#include "FillCubeSequence.h"
#include "BlinkSequence.h"
#include "CubeBounceSequence.h"
#include "ThrobberSequence.h"
#include "TranslationTestSequence.h"
#include "PlaneSequence.h"
#include "HackspaceSequence.h"
#include "OutlineSequence.h"
#include "SnakeSequence.h"
#include "Snake2Sequence.h"

#define PERIPH_HC SYSCTL_PERIPH_GPIOE
#define PORT_HC GPIO_PORTE_BASE

#define PERIPH_LATCH SYSCTL_PERIPH_GPIOB
#define PORT_LATCH GPIO_PORTB_BASE

#define PIN_ALL 0xFF

#define SEQ_COUNT 9


#define LED RED_LED

char cube[8][8];
char (&ref)[8][8] = cube;
int sidx = 0;
int cycleCounter = 0;


HC138N hc(PORT_HC);
LayerControl layers;

BlinkSequence s1(ref);
CubeBounceSequence s2(ref);
FillCubeSequence s3(ref);
HackspaceSequence s4(ref);
OutlineSequence s5(ref);
PlaneSequence s6(ref);
//SnakeSequence s7(ref);
Snake2Sequence s8(ref);
ThrobberSequence s9(ref);
TranslationTestSequence s10(ref);

//Sequence * s = &s9; // sequence s points to the address of the f1 object (polymorphism)
Sequence *seqs[SEQ_COUNT] = { &s3, &s5, &s9, &s1, &s2, &s6, &s4, &s10, &s8 };
Sequence *s = seqs[sidx];

void setup()
{

	// Connections

	// PORTE - HC138
	// PE0 - In0
	// PE1 - In1
	// PE2 - In2
	// PE3 - Enable

	// PORTB - Latch chip inputs
	// PB0...7

	// Ground (Layer control)
	// PA2..7,PC6,PC7



	// Enable peripherals
	SysCtlPeripheralEnable(PERIPH_HC);
	SysCtlPeripheralEnable(PERIPH_LATCH);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
        pinMode(LED, OUTPUT);

        digitalWrite(LED, HIGH);
        hc.init();
        layers.init();
        digitalWrite(LED, LOW);

	// Setup Port expander, latch, layer control
	GPIOPinTypeGPIOOutput(PORT_LATCH, PIN_ALL);

	// Turn everything off
	GPIOPinWrite(PORT_LATCH, PIN_ALL, 0x00);
	for (char i = 0; i < 8; i++)
		hc.setp(i);

	s->initialize();
}

int lcyc=0;

void loop()
{
    if (lcyc == 0) {
      digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
      lcyc=1;
    }
    else {
      digitalWrite(LED, LOW);
      lcyc = 0;
    }
    
	// repeat cube image a number of times before moving on to next image
	for (int showdelay = 0; showdelay < s->delay; showdelay++)
		for (int l = 0; l < 8; l++)
		{
			// Loop round latched in this layer
			for (int r = 0; r < 8; r++)
			{
				// Set a outputs for a single row
				GPIOPinWrite(PORT_LATCH, PIN_ALL, (*s->cube)[l][r]);
				// Latch in outputs
				hc.setp(r);
			}
				// Enable layer for a short time
			layers.on(l);
			SysCtlDelay(20000);
			layers.off();
		}

	s->next();
	cycleCounter++;

	if (s->finished || (s->runCycles != 0 && cycleCounter > s->runCycles))
	{
		sidx++;
		if (sidx > SEQ_COUNT - 1) sidx = 0;
			s = seqs[sidx];

		s->initialize();
		cycleCounter = 0;
	}
}

