/*
 * PlaneSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "PlaneSequence.h"

PlaneSequence::PlaneSequence(char (&ref)[8][8]) : Sequence(ref) {}

void PlaneSequence::initialize(){
	Sequence::initialize();
	i = 0;
	ip = 1;
	delay = 100;
	name = "Plane";
}

void PlaneSequence::next(){

	cubeOff();

	DrawXYPlane(i);
	DrawXYPlane(7 - i);

	DrawXZPlane(i);
	DrawXZPlane(7 - i);

	DrawYZPlane(i);
	DrawYZPlane(7 - i);

	if (i == 0 || i == 3)
		delay = 100;
	else
		delay = 10;

	i += ip;

	if (i == 3) ip = -1;
	else if (i == 0) ip = 1;
}
