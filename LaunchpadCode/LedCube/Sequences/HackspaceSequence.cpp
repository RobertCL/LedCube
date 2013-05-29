/*
 * HackspaceSequence.cpp
 *
 *  Created on: 29 May 2013
 *      Author: robert
 */

#include "HackspaceSequence.h"

const char text[] = { 'H', 'A', 'C', 'K', 'S', 'P', 'A', 'C', 'E' };
const int textLen = 9;

HackspaceSequence::HackspaceSequence() {
	letterNo = 0;
	transPos = -1;
	d = 50;
}

void HackspaceSequence::next() {
	if (transPos == -1) {
		drawLetter(text[letterNo], 0);
		drawLetter(text[letterNo], 1);

		d = 100;

		letterNo++;
		if (letterNo == textLen)
			letterNo = 0;
	}

	else {
		Translate(0, 1, 0);
		d = 10;
	}

	transPos++;
	if (transPos == 9)
		transPos = -1;
}

int HackspaceSequence::delay(){
	return d;
}

