/*
 * BlinkSequence.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef BLINKSEQUENCE_H_
#define BLINKSEQUENCE_H_

#include "Sequence.h"

class BlinkSequence: public Sequence {
public:
	BlinkSequence();
	virtual ~BlinkSequence();

	virtual void next();
	virtual int delay();

private:
	bool isOn;
	int delayTime;
	int delayChange;
};

#endif /* BLINKSEQUENCE_H_ */
