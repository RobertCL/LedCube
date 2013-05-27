/*
 * PlaneSequence.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef PLANESEQUENCE_H_
#define PLANESEQUENCE_H_

#include "Sequence.h"

class PlaneSequence : public Sequence {
public:
	PlaneSequence();

	virtual int delay();
	virtual void next();

private:
	int i;
	int ip;
	int d;
};

#endif /* PLANESEQUENCE_H_ */
