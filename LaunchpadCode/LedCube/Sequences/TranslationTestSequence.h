/*
 * TranslationTestSequence.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef TRANSLATIONTESTSEQUENCE_H_
#define TRANSLATIONTESTSEQUENCE_H_

#include "Sequence.h"

class TranslationTestSequence: public Sequence {
public:
	TranslationTestSequence(char (&ref)[8][8]);

	virtual void next();

private:
	int count;
	int dir;
	int plane;
	bool drawPlaneNext;
	void clearAndDrawInitialPlane();
};

#endif /* TRANSLATIONTESTSEQUENCE_H_ */
