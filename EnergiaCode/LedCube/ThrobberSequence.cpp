/*
 * ThrobberSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "ThrobberSequence.h"

ThrobberSequence::ThrobberSequence(char (&ref)[8][8]) : Sequence(ref) {}

void ThrobberSequence::initialize(){
	Sequence::initialize();
	count = 0;
	countp = 1;
	name = "Throbber";
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
		delay = 15;
	else
		delay = 6;

	count += countp;

	if (count == 4) countp = -1;
	else if (count == 0) countp = 1;
}
