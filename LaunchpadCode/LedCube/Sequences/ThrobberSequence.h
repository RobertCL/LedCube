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
	ThrobberSequence(char (&ref)[8][8]);

	virtual void next();

private:
	int count;
	int countp;
};

#endif /* THROBBERSEQUENCE_H_ */
