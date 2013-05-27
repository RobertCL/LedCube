/*
 * CubeBounceSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "CubeBounceSequence.h"

CubeBounceSequence::CubeBounceSequence() {
	x = 3;
	y = 0;
	z = 1;

	xp = 1;
	yp = 1;
	zp = 1;
}

CubeBounceSequence::~CubeBounceSequence() {}

void CubeBounceSequence::next(){
	int size = 3;
	cubeOff();
	drawCube(x, y, z, size);

	x += xp;
	y += yp;
	z += zp;

	if (x + xp + size - 1 > 7) xp = -1;
	else if (x + xp < 0) xp = 1;

	if (y + yp + size - 1 > 7) yp = -1;
	else if (y + yp < 0) yp = 1;

	if (z + zp + size - 1 > 7) zp = -1;
	else if (z + zp < 0) zp = 1;
}

int CubeBounceSequence::delay(){
	return 10;
}
