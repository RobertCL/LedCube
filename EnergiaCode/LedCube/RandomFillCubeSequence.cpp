#include "RandomFillCubeSequence.h"
#include <stdlib.h>

RandomFillCubeSequence::RandomFillCubeSequence(char (&ref)[8][8]) : Sequence(ref) {}

void RandomFillCubeSequence::initialize(){
  Sequence::initialize();
  delay = 1;
  runCycles = 512;
  name = "RandomFillCube";
}

int cycle = 0;

void RandomFillCubeSequence::next(){

  cycle++;
  
  // Seems to need a way to abort because in some cases no available
  // random position can be found, even when the cube isn't full.
  for(int i=0; i<150 ;i++) {
    int x = rand() % 8;
    int y = rand() % 8;
    int z = rand() % 8;
        
    if (!getState(x,y,z)) {
      setOn(x,y,z);
      return;
    }
  }
  
  Serial.print("No random position found on cycle ");
  Serial.println(cycle);
}
