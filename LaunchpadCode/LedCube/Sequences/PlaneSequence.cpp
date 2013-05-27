/*
 * PlaneSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "PlaneSequence.h"

PlaneSequence::PlaneSequence() {
	i = 0;
	ip = 1;
	d = 100;
}

int PlaneSequence::delay(){
	return d;
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
		d = 100;
	else
		d = 10;

	i += ip;

	if (i == 3) ip = -1;
	else if (i == 0) ip = 1;
}
