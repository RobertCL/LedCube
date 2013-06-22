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
	SnakeSequence(char (&ref)[8][8]);

	void initialize();
	void next();
};

#endif /* SNAKESEQUENCE_H_ */
