/*
 * ThrobberSequence.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef THROBBERSEQUENCE_H_
#define THROBBERSEQUENCE_H_

#include "Sequence.h"

class ThrobberSequence: public Sequence {
public:
	ThrobberSequence();

	virtual void next();
	virtual int delay();

private:
	int count;
	int countp;
	int d;
};

#endif /* THROBBERSEQUENCE_H_ */
