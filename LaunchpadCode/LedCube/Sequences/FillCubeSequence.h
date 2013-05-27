/*
 * FillCubeSequence.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef FILLCUBESEQUENCE_H_
#define FILLCUBESEQUENCE_H_

#include "Sequence.h"

class FillCubeSequence : public Sequence {
public:
	FillCubeSequence();
	~FillCubeSequence();

	virtual void next();
	virtual int delay();

private:
	int x;
	int y;
};

#endif /* FILLCUBESEQUENCE_H_ */
