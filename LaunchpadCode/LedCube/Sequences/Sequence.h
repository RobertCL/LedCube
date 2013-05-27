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
	~Sequence();

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

};

#endif /* SEQUENCE_H_ */
