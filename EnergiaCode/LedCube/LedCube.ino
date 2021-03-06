// Connections
// Note:   PB7 = PD1, PB6 = PD0
// From http://www.ti.com/lit/ug/spmu289c/spmu289c.pdf section 2.4
// (2) J2.06 (PB7) is also connected via a 0-Ω resistor to J3.04 (PD1)
// (3) J2.07 (PB6) is also connected via a 0-Ω resistor to J3.03 (PD0)
    
// PORTE - HC138
// PE0 - In0
// PE1 - In1
// PE2 - In2
// PE3 - Enable
  
// PORTB - Latch chip inputs
// PB0...7
  
// Ground (Layer control)
// PA2..7,PC6,PC7
  
// Onboard Serial Virtual COM port
// PA0 - RX
// PA1 - TX
// Onboard LED
// R,B,G = PF1, PF2, PF3
// Onboard switches
// SW1 = PF4
// SW2 = PF0

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
#include "CubeGrowSequence.h"
#include "RandomFillCubeSequence.h"

#define PERIPH_HC SYSCTL_PERIPH_GPIOE
#define PORT_HC GPIO_PORTE_BASE

#define PERIPH_LATCH SYSCTL_PERIPH_GPIOB
#define PORT_LATCH GPIO_PORTB_BASE

#define PIN_ALL 0xFF

char cube[8][8]; // contains the pixels of the cube
char (&ref)[8][8] = cube; // ref is a reference to cube
int sidx = 0; // index of the sequence we are currently playing from seqs.
int cycleCounter = 0; // number of cycles we've played in the current sequence

HC138N hc(PORT_HC); // port multiplexer controller
LayerControl layers; // layer controller for turning on/off ground to layers in cube

// Instances of sequence classes that provide display data
BlinkSequence sBlink(ref);
CubeBounceSequence sCubeBounce(ref);
FillCubeSequence sFillCube(ref);
HackspaceSequence sHackspace(ref);
OutlineSequence sOutline(ref);
PlaneSequence sPlane(ref);
Snake2Sequence sSnake(ref);
ThrobberSequence sThrobber(ref);
TranslationTestSequence sTranslation(ref);
CubeGrowSequence sCubeGrow(ref);
RandomFillCubeSequence sRandomFill(ref);

// seqs is an array of sequences that we will run in order in the cube.
// Sequence * s = &s9; // sequence s points to the address of the f1 object (polymorphism)
#define SEQ_COUNT 11
Sequence *seqs[SEQ_COUNT] = { &sRandomFill, &sCubeGrow, &sFillCube, &sOutline, &sThrobber, &sBlink, &sCubeBounce, &sPlane, &sHackspace, &sTranslation, &sSnake };
Sequence *s = seqs[sidx]; // the current sequence that is being run.

void setup()
{
  // Startup Serial
  Serial.begin(115200);
  Serial.println("LED Cube startup...");

  // Init helper classes
  Serial.println("Initialise helpers...");
  hc.init();
  layers.init();
  
  // Setup Port expander, latch, layer control
  GPIOPinTypeGPIOOutput(PORT_LATCH, PIN_ALL);
  
  // Turn everything off
  Serial.println("Clear cube...");
  GPIOPinWrite(PORT_LATCH, PIN_ALL, 0x00);
  for (char i = 0; i < 8; i++)
    hc.setp(i);
  
  // Initialise the first sequence before entering the loop
  s->initialize();
  Serial.print("Starting sequence - ");
  Serial.println(s->name);
}

void loop()
{
  // read data from serial into command buffer.
  feedCommandBuffer();
  
  // repeat cube image a number of times before moving on to next image
  for (int showdelay = 0; showdelay < s->delay; showdelay++)
    for (int l = 0; l < 8; l++) // foreach layer
    {
      // Loop round latched in this layer
      for (int r = 0; r < 8; r++) // foreach row in layer
      {
        // Set outputs for a single row
        GPIOPinWrite(PORT_LATCH, PIN_ALL, (*s->cube)[l][r]);
        // Latch in outputs
        hc.setp(r);
      }
      
      // Enable layer for a short time
      layers.on(l);
      SysCtlDelay(20000);
      layers.off();
    }

  // move sequence on to next frame of animation
  s->next();
  cycleCounter++;

  // check to see if sequence has reported completion or run for sufficient time
  if (s->finished || (s->runCycles != 0 && cycleCounter > s->runCycles))
  {
    // move on to next sequence
    sidx++;
    if (sidx > SEQ_COUNT - 1) sidx = 0;
      s = seqs[sidx];

    // initialise sequence and reset counters.
    s->initialize();
    cycleCounter = 0;
    Serial.print("Starting sequence - ");
    Serial.println(s->name);
  }
}

String command;

void feedCommandBuffer()
{
  while (Serial.available() > 0)
  {
    char inByte = Serial.read();
    if (inByte == '\n')
    {
      Serial.print(command);
      // Process command
      if (command == "n") // Skip to next sequence
      {
        s->finished = true;
      }
      else
      {
        Serial.print(" - unknown command");
      }
      
      Serial.println(" - OK");
      command = "";
    }
    else
    {
      command += inByte;
    }
  }
}
