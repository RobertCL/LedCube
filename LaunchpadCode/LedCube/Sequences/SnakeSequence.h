/*
 * SnakeSequence.h
 *
 *  Created on: 29 May 2013
 *      Author: robert
 */

#ifndef SNAKESEQUENCE_H_
#define SNAKESEQUENCE_H_

#include "Sequence.h"

class SnakeSequence: public Sequence {
public:
	SnakeSequence();

	virtual void next();
	virtual int delay();

private:
	void set(int x, int y, int z);
	bool get(int x, int y, int z);

	// current location of the head of the snake
	//int head_x, head_y, head_z;
	//int delta_x, delta_y, delta_z;
};

#endif /* SNAKESEQUENCE_H_ */
