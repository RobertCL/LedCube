#ifndef CUBEGROWSEQUENCE_H_
#define CUBEGROWSEQUENCE_H_

#include "Sequence.h"
#include "CubeTracker.h"

class CubeGrowSequence: public Sequence {
  
public:
  CubeGrowSequence(char (&ref)[8][8]);

  void initialize();
  void next();

private:
  int x = 0;
  int y = 0;
  int z = 0;
  int s = 1;

  int ix = 0;
  int iy = 0;
  int iz = 0;
  int is = 1;
  
  int i = 0;
};

#endif /* CUBEGROWSEQUENCE_H_ */
