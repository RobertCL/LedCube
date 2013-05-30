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

	// Set the LED at x,y,z on
	void setOn(int x, int y, int z);
	// Get the state of the LED at x,y,z, true = on, false = off
	bool getState(int x, int y, int z);

	// Draw a cube of size at x,y,z (callee needs to check overflows)
	void drawCube(int x, int y, int z, int size);

	// Draws a solid plane in the X-Z axis at atY on the y-axis
	void DrawXZPlane(int atY);
	// Draws a solid plane in the Y-Z axis at atX on the x-axis
	void DrawYZPlane(int atX);
	// Draws a solid plane in the X-Y axis at atZ on the z-axis
	void DrawXYPlane(int atZ);

	// Translates (moves) the cube array in the given (x,y,z) direction
	// x,y,z should be -1 or 1
	// data pushed off the cube is lost, rows made empty are set to off (zero)
	void Translate(int x, int y, int z);

	// Draws a letter (caps only) at position atY
	void drawLetter(char l, int atY);
};

#endif /* SEQUENCE_H_ */
