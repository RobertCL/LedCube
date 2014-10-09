/*
 * BlinkSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "BlinkSequence.h"

BlinkSequence::BlinkSequence(char (&ref)[8][8]) : Sequence(ref) {}

void BlinkSequence::initialize(){
	Sequence::initialize();
	isOn = false;
	delay = 50;
	delayChange = -1;
	name = "Blink";
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
