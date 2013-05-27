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
	cubeOff();
	drawMiniCube(x, y, z);

	x += xp;
	y += yp;
	z += zp;

	if (x + xp + 1 > 7) xp = -1;
	else if (x + xp < 0) xp = 1;

	if (y + yp + 1 > 7) yp = -1;
	else if (y + yp < 0) yp = 1;

	if (z + zp + 1 > 7) zp = -1;
	else if (z + zp < 0) zp = 1;
}

void CubeBounceSequence::drawMiniCube(int atX, int atY, int atZ){
	char t = 0x03 << atX;

	cube[atZ][atY] = t;
	cube[atZ][atY+1] = t;
	cube[atZ+1][atY] = t;
	cube[atZ+1][atY+1] = t;
}

int CubeBounceSequence::delay(){
	return 8;
}
