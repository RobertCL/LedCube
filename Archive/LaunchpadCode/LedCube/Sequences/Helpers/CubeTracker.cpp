/*
 * CubeTracker.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "CubeTracker.h"

CubeTracker::CubeTracker(int x, int y, int z, int size, int xp, int yp, int zp) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->xp = xp;
	this->yp = yp;
	this->zp = zp;
	this->size = size;
}

void CubeTracker::move(){
	x += xp;
	y += yp;
	z += zp;

	if (x + xp + size - 1 > 6) xp = -1; // Note, only 6, gives a more "random" movement bouncing in a 8x8x7 box.
	else if (x + xp < 0) xp = 1;

	if (y + yp + size - 1 > 7) yp = -1;
	else if (y + yp < 0) yp = 1;

	if (z + zp + size - 1 > 7) zp = -1;
	else if (z + zp < 0) zp = 1;
}

