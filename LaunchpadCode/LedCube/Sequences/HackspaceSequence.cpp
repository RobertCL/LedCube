/*
 * HackspaceSequence.cpp
 *
 *  Created on: 29 May 2013
 *      Author: robert
 */

#include "HackspaceSequence.h"

const char text[] = { 'H', 'A', 'C', 'K', 'S', 'P', 'A', 'C', 'E' };
const int textLen = 9;

HackspaceSequence::HackspaceSequence(char (&ref)[8][8]) : Sequence(ref) {
	letterNo = 0;
	transPos = -1;
	delay = 50;
}

void HackspaceSequence::next() {
	if (transPos == -1) {
		drawLetter(text[letterNo], 0);
		drawLetter(text[letterNo], 1);

		delay = 100;

		letterNo++;
		if (letterNo == textLen)
			letterNo = 0;
	}

	else {
		Translate(0, 1, 0);
		delay = 10;
	}

	transPos++;
	if (transPos == 4)
		transPos = -1;
}
