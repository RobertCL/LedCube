/*
 * Sequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "Sequence.h"

Sequence::Sequence() {
	// Start with a blank cube
	cubeOff();
}

Sequence::~Sequence() {
}

int Sequence::delay(){
	return 1;
}

void Sequence::setCube(char d){
	for (int i=0; i<8; i++)
			for (int j=0; j<8; j++)
				cube[i][j] = d;
}

void Sequence::cubeOff(){
	setCube(0x00);
}

void Sequence::cubeOn(){
	setCube(0xFF);
}
