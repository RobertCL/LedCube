#include "CubeGrowSequence.h"

CubeGrowSequence::CubeGrowSequence(char (&ref)[8][8]) : Sequence(ref) {}

void CubeGrowSequence::initialize(){
  Sequence::initialize();
  delay = 4;
  runCycles = 256;
  name = "CubeGrow";
}

void CubeGrowSequence::next(){
  cubeOff();
  drawCube(x, y, z, s);

  s += is;
  x += ix;
  y += iy;
  z += iz;
    
  if (s == 8 || s == 1) {
    i++;
    is *= -1;
    
    switch (i)
    {
      case 1:
        ix = 1;  iy = 1;  iz = 1;  break;
      case 2:
        ix = -1; iy = -1; iz = -1; break;

      case 3:
        ix = 0;  iy = 1;  iz = 1;  break;
      case 4:
        ix = 0;  iy = -1; iz = -1; break;
        
      case 5:
        ix = 1;  iy = 0;  iz = 1;  break;
      case 6:
        ix = -1; iy = 0;  iz = -1; break;

      case 7:
        ix = 1;  iy = 1;  iz = 0;  break;
      case 8:
        ix = -1; iy = -1; iz = 0; break;

      case 9:
        ix = 1;  iy = 0;  iz = 0;  break;
      case 10:
        ix = -1; iy = 0; iz = 0; break;

      case 11:
        ix = 0;  iy = 1;  iz = 0;  break;
      case 12:
        ix = 0;  iy = -1; iz = 0; break;

      case 13:
        ix = 0;  iy = 0;  iz = 1;  break;
      case 14:
        ix = 0;  iy = 0;  iz = -1; break;
    }
    
    if (i == 14) {
      i = 0;
    }
  } 
}
