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
	Snake2Sequence(char (&ref)[8][8]);

	virtual void next();

private:
	#define MAX_SNAKE_LEN 15

	// Where is the snake
	// [0] is the head
	char snake_x[15];
	char snake_y[15];
	char snake_z[15];

	// How long is the snake
	char snakeLen;
	// How much more does the snake want to grow by
	char growBy;

	// Next move
	short delta_x, delta_y, delta_z;

	// >0 if the snake is stuck
	char stuck;

	// Where is the food
	char food_x[5];
	char food_y[5];
	char food_z[5];
	// How much food is there
	char foodCount;

	void initSnake();

	// Draws the current snake in the cube
	void drawSnakeInCube();
	// Draws the food in the cube
	void drawFoodInCube();

	// Is a point on the snake (used for collision test)
	bool isSnake(char x, char y, char z);
	// Move the snake "along" one
	void shuffleSnake();

	// Is a point food
	short isFood(char x, char y, char z);
};

#endif /* SNAKE2SEQUENCE_H_ */
