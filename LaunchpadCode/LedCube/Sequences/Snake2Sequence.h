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
	#define FOOD_COUNT 4

	// Where is the snake
	// [0] is the head
	char snake_x[MAX_SNAKE_LEN];
	char snake_y[MAX_SNAKE_LEN];
	char snake_z[MAX_SNAKE_LEN];

	// How long is the snake
	char snakeLen;
	// How much more does the snake want to grow by
	char growBy;

	// Next move
	short delta_x, delta_y, delta_z;

	// >0 if the snake is stuck
	char stuck;

	// Where is the food
	char food_x[FOOD_COUNT];
	char food_y[FOOD_COUNT];
	char food_z[FOOD_COUNT];

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
