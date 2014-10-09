/*
 * HackspaceSequence.cpp
 *
 *  Created on: 29 May 2013
 *      Author: robert
 */

#include "HackspaceSequence.h"

const char text[] = { 'H', 'A', 'C', 'K', 'S', 'P', 'A', 'C', 'E' };
#define TEXT_LEN 9

HackspaceSequence::HackspaceSequence(char (&ref)[8][8]) : Sequence(ref) {}

void HackspaceSequence::initialize(){
	Sequence::initialize();
	letterNo = 0;
	transPos = -1;
	delay = 50;
	runCycles = 0;
	name = "Hackspace";
}

void HackspaceSequence::next() {
	if (transPos == -1) {
		drawLetter(text[letterNo], 0);
		drawLetter(text[letterNo], 1);

		delay = 100;

		letterNo++;
		if (letterNo == TEXT_LEN)
			letterNo = -1;
	}

	else {
		Translate(0, 1, 0);
		delay = 10;
	}

	transPos++;
	if (transPos == 8)
	{
		transPos = -1;
		if (letterNo == -1)
			finished = true;
	}
}
