/*
 * Snake2Sequence.h
 *
 *  Created on: 30 May 2013
 *      Author: robert
 */

#ifndef SNAKE2SEQUENCE_H_
#define SNAKE2SEQUENCE_H_

#include "Sequence.h"

class Snake2Sequence: public Sequence {
public:
	Snake2Sequence();

	virtual void next();

private:
	#define MAX_SNAKE_LEN 16

	// Where is the snake
	// [0] is the head
	char snake_x[16];
	char snake_y[16];
	char snake_z[16];

	// How long is the snake
	char snakeLen;
	// How much more does the snake want to grow by
	char growBy;

	// Next move
	short delta_x, delta_y, delta_z;

	// >0 if the snake is stuck
	char stuck;

	void initSnake();

	// Draws the current snake in the cube
	void drawSnakeInCube();

	// Is a point on the snake (used for collision test)
	bool isSnake(char x, char y, char z);
	// Move the snake "along" one
	void shuffleSnake();
};

#endif /* SNAKE2SEQUENCE_H_ */
