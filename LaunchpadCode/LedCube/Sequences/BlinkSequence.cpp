/*
 * BlinkSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "BlinkSequence.h"

BlinkSequence::BlinkSequence() {
	isOn = false;
	delay = 50;
	delayChange = -1;
}

void BlinkSequence::next(){
	if (isOn)
		cubeOff();
	else
		cubeOn();

	isOn = !isOn;

	delay += delayChange;
	if (delay == 1 || delay == 50)
		delayChange *= -1;
}
