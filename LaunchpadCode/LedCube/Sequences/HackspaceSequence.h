/*
 * HackspaceSequence.h
 *
 *  Created on: 29 May 2013
 *      Author: robert
 */

#ifndef HACKSPACESEQUENCE_H_
#define HACKSPACESEQUENCE_H_

#include "Sequence.h"

class HackspaceSequence: public Sequence {
public:
	HackspaceSequence(char (&ref)[8][8]);

	virtual void next();

private:
	int letterNo;
	int transPos;
};

#endif /* HACKSPACESEQUENCE_H_ */
