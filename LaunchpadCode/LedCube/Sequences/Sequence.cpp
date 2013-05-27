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

void Sequence::DrawXZPlane(int atY){
	cube[0][atY] = 0xFF;
	cube[1][atY] = 0xFF;
	cube[2][atY] = 0xFF;
	cube[3][atY] = 0xFF;
	cube[4][atY] = 0xFF;
	cube[5][atY] = 0xFF;
	cube[6][atY] = 0xFF;
	cube[7][atY] = 0xFF;
}

void Sequence::DrawYZPlane(int atX){
	for (int z = 0; z < 8; z++)
		for (int y = 0; y < 8; y++)
			cube[z][y] |= 0x01 << atX;
}

void Sequence::DrawXYPlane(int atZ){
	cube[atZ][0] = 0xFF;
	cube[atZ][1] = 0xFF;
	cube[atZ][2] = 0xFF;
	cube[atZ][3] = 0xFF;
	cube[atZ][4] = 0xFF;
	cube[atZ][5] = 0xFF;
	cube[atZ][6] = 0xFF;
	cube[atZ][7] = 0xFF;
}

void Sequence::Translate(int x, int y, int z){
	if (x == 1) {
		for (int z = 0; z < 8 ;z++)
			for (int y = 0; y < 8; y++)
				cube[z][y] = cube[z][y] << 1;
	}
	else if (x == -1) {
		for (int z = 0; z < 8 ;z++)
			for (int y = 0; y < 8; y++)
				cube[z][y] = cube[z][y] >> 1;
	}
	if (y == 1)	{
		for (int z = 0; z < 8; z++) {
			for (int y = 7; y > 0; y--)
				cube[z][y] = cube[z][y-1];

			cube[z][0] = 0x00;
		}
	}
	else if (y == -1) {
		for (int z = 0; z < 8; z++) {
			for (int y = 1; y < 8; y++)
				cube[z][y-1] = cube[z][y];

			cube[z][7] = 0x00;
		}
	}
	if (z == 1) {
		for (int y = 0; y < 8; y++) {
			for (int z = 7; z > 0; z--)
				cube[z][y] = cube[z-1][y];

			cube[0][y] = 0x00;
		}
	}
	else if (z == -1) {
		for (int y = 0; y < 8; y++)	{
			for (int z = 1; z < 8; z++)
				cube[z-1][y] = cube[z][y];

			cube[7][y] = 0x00;
		}
	}
}
