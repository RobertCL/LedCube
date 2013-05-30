/*
 * CubeBounceSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "CubeBounceSequence.h"

CubeBounceSequence::CubeBounceSequence() :
	cube1(3, 0, 1, 3, 1, 1, 1),
	cube2(0, 4, 3, 2, -1, -1, -1) {
	delay = 7;
}

CubeBounceSequence::~CubeBounceSequence() {}

void CubeBounceSequence::next(){
	cubeOff();
	drawCube(cube1.x, cube1.y, cube1.z, cube1.size);
	cube1.move();
	drawCube(cube2.x, cube2.y, cube2.z, cube2.size);
	cube2.move();
}
