#include "RandomFillCubeSequence.h"
#include <stdlib.h>

RandomFillCubeSequence::RandomFillCubeSequence(char (&ref)[8][8]) : Sequence(ref) {}

void RandomFillCubeSequence::initialize(){
  Sequence::initialize();
  delay = 1;
  runCycles = 512;
  name = "FillCube";
}

void RandomFillCubeSequence::next(){

  for(int i=0; i<100 ;i++) {
    int x = rand() % 8;
    int y = rand() % 8;
    int z = rand() % 8;
        
    if (!getState(x,y,z)) {
      setOn(x,y,z);
      return;
    }
  }
  Serial.println("No random position found");
}
