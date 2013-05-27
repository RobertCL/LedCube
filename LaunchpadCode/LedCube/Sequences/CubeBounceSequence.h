/*
 * CubeBounceSequence.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef CUBEBOUNCESEQUENCE_H_
#define CUBEBOUNCESEQUENCE_H_

#include "Sequence.h"

class CubeBounceSequence: public Sequence {
public:
	CubeBounceSequence();
	virtual ~CubeBounceSequence();

	virtual void next();
	virtual int delay();

private:
	int x;
	int y;
	int z;

	int xp;
	int yp;
	int zp;

	void drawMiniCube(int atX, int atY, int atZ);
};

#endif /* CUBEBOUNCESEQUENCE_H_ */
