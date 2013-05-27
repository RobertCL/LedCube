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

void Sequence::drawCube(int x, int y, int z, int size){
	char t = 0x00;
	for (int i=0; i<size; i++)
		t = (t << 1) + 1;
	t = t << x;

	for (int yp=0; yp<size; yp++)
		for (int zp=0; zp<size; zp++)
			cube[z + zp][y + yp] = t;
}
