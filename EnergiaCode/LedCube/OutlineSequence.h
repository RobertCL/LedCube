/*
 * OutlineSequence.h
 *
 *  Created on: 29 May 2013
 *      Author: robert
 */

#ifndef OUTLINESEQUENCE_H_
#define OUTLINESEQUENCE_H_

#include "Sequence.h"

class OutlineSequence: public Sequence {
public:
	OutlineSequence(char (&ref)[8][8]);

	void initialize();
	void next();
};

#endif /* OUTLINESEQUENCE_H_ */
