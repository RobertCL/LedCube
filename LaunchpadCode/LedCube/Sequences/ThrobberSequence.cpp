/*
 * ThrobberSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "ThrobberSequence.h"

ThrobberSequence::ThrobberSequence() {
	count = 0;
	countp = 1;
	d = 10;
}

int ThrobberSequence::delay(){
	return d;
}

void ThrobberSequence::next(){
	cubeOff();

	if (count != 0)
	{
		int cubeSize = count * 2;
		int loc = 4 - count;
		drawCube(loc, loc, loc, cubeSize);
	}

	if (count == 4 || count == 0)
		d = 10;
	else
		d = 4;

	count += countp;

	if (count == 4) countp = -1;
	else if (count == 0) countp = 1;
}
