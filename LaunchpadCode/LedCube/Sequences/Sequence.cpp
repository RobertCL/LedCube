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
	delay = 10;
}

Sequence::~Sequence() {
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

void Sequence::setOn(int x, int y, int z) {
	cube[z][y] |= 1<<x;
}

bool Sequence::getState(int x, int y, int z) {
	return cube[z][y] &= 1<<x;
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

// 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
char letterData[26][8] = {
		{ 0xC3, 0xC2, 0x7E, 0x7E, 0x66, 0x66, 0x3C, 0x18 }, // A
		{}, // B
		{ 0xFE,	0xFF, 0x07, 0x03, 0x03, 0x07, 0xFF,	0xFE }, // C
		{}, // D
		{ 0xFF, 0xFF, 0x03, 0x3F, 0x3F, 0x03, 0xFF, 0xFF }, // E
		{}, // F
		{}, // G
		{ 0xC3, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3 }, // H
		{}, // I
		{}, // J
		{ 0xC3, 0x63, 0x33, 0x0F, 0x0F, 0x33, 0x63, 0xC3 }, // K
		{}, // L
		{}, // M
		{}, // N
		{}, // O
		{ 0x03, 0x03, 0xFF, 0xFF, 0xC3, 0xC3, 0xFF, 0xFF }, // P
		{}, // Q
		{}, // R
		{ 0xFF, 0xFF, 0xC0, 0xFF, 0xFF, 0x03, 0xFF, 0xFF }, // S
		{}, // T
		{}, // U
		{}, // V
		{}, // W
		{}, // X
		{}, // Y
		{}  // Z
};

void Sequence::drawLetter(char l, int atY){
	int idx = l - 'A';

	cube[7][atY] = letterData[idx][7];
	cube[6][atY] = letterData[idx][6];
	cube[5][atY] = letterData[idx][5];
	cube[4][atY] = letterData[idx][4];
	cube[3][atY] = letterData[idx][3];
	cube[2][atY] = letterData[idx][2];
	cube[1][atY] = letterData[idx][1];
	cube[0][atY] = letterData[idx][0];
}
