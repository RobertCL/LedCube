/*
 * Sequence.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

class Sequence {
public:
	Sequence();
	virtual ~Sequence();

	char cube[8][8]; // Cube[layer, row]
	virtual void next() = 0;
	virtual int delay();

protected:
	// Set all rows in cube to be the same
	void setCube(char d);
	// Turn all LED's off
	void cubeOff();
	// Turn all LED's on
	void cubeOn();
	// Draw a cube of size at x,y,z (callee needs to check overflows)
	void drawCube(int x, int y, int z, int size);
};

#endif /* SEQUENCE_H_ */
