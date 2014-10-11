#ifndef RANDOMFILLCUBESEQUENCE_H_
#define RANDOMFILLCUBESEQUENCE_H_

#include "Sequence.h"

class RandomFillCubeSequence : public Sequence {
public:
  RandomFillCubeSequence(char (&ref)[8][8]);

  void initialize();
  void next();

};

#endif /* RANDOMFILLCUBESEQUENCE_H_ */
