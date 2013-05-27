/*
 * BlinkSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "BlinkSequence.h"

BlinkSequence::BlinkSequence() {
	isOn = false;
	delayTime = 50;
	delayChange = -1;
}

BlinkSequence::~BlinkSequence() { }

void BlinkSequence::next(){
	if (isOn)
		cubeOff();
	else
		cubeOn();

	isOn = !isOn;

	delayTime += delayChange;
	if (delayTime == 1 || delayTime == 50)
		delayChange *= -1;
}

int BlinkSequence::delay(){
	return delayTime;
}

