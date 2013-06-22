/*
 * CubeBounceSequence.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef CUBEBOUNCESEQUENCE_H_
#define CUBEBOUNCESEQUENCE_H_

#include "Sequence.h"
#include "Helpers/CubeTracker.h"

class CubeBounceSequence: public Sequence {
public:
	CubeBounceSequence(char (&ref)[8][8]);

	void initialize();
	void next();

private:
	CubeTracker cube1;
	CubeTracker cube2;
};

#endif /* CUBEBOUNCESEQUENCE_H_ */
