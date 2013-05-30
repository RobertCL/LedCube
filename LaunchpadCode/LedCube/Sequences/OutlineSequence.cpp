/*
 * OutlineSequence.cpp
 *
 *  Created on: 29 May 2013
 *      Author: robert
 */

#include "OutlineSequence.h"

OutlineSequence::OutlineSequence() {
	cube[0][0] = 0xFF;
	cube[7][0] = 0xFF;

	cube[0][7] = 0xFF;
	cube[7][7] = 0xFF;

	for (int i = 1; i < 7; i++){
		cube[i][0] = 0x81;
		cube[i][7] = 0x81;

		cube[0][i] = 0x81;
		cube[7][i] = 0x81;
	}
}

void OutlineSequence::next(){
}

