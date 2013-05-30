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
};

#endif /* SNAKESEQUENCE_H_ */
