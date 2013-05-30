/*
 * Snake2Sequence.cpp
 *
 *  Created on: 30 May 2013
 *      Author: robert
 */

#include "Snake2Sequence.h"
#include <stdlib.h>

Snake2Sequence::Snake2Sequence() {
	initSnake();
}

void Snake2Sequence::initSnake(){
	delay = 1;
	stuck = 0;

	for (int i = 0; i < MAX_SNAKE_LEN; i++){
		snake_x[i] = 0;
		snake_y[i] = 0;
		snake_z[i] = 0;
	}
	snakeLen = 1;
	growBy = 15;

	delta_x = 1;
	delta_y = 0;
	delta_z = 0;

	drawSnakeInCube();
}

void Snake2Sequence::drawSnakeInCube(){
	cubeOff();
	for (int i = 0; i < snakeLen; i++){
		setOn(snake_x[i], snake_y[i], snake_z[i]);
	}
}

void Snake2Sequence::shuffleSnake(){
	for (int i = snakeLen - 2; i >= 0; i--){
		snake_x[i + 1] = snake_x[i];
		snake_y[i + 1] = snake_y[i];
		snake_z[i + 1] = snake_z[i];
	}

	if (growBy > 0){
		snakeLen++;
		growBy--;
	}
}

bool makeRandomTurn(){
	return rand() > 2 * (RAND_MAX / 3);
}

bool Snake2Sequence::isSnake(char x, char y, char z){
	for (int i = 0; i < snakeLen; i++)
		if (snake_x[i] == x && snake_y[i] == y && snake_z[i] == z)
			return true;

	return false;
}

void Snake2Sequence::next(){

	if (stuck > 0) {
		if (stuck < 10)
			Translate(0, 0, -1);

		stuck--;
		if (stuck == 0)
			initSnake();

		return;
	}


	// Work out if we need to turn because either
	// - we are about to go out of the cube
	// - we are about to eat ourselves
	// - we just randomly fancy turning
	short attempts = 0;
	while (true){
		int next_x = snake_x[0] + delta_x;
		int next_y = snake_y[0] + delta_y;
		int next_z = snake_z[0] + delta_z;
		if (next_x < 0 || next_x > 7 || next_y < 0 || next_y > 7 || next_z < 0 || next_z > 7
				|| isSnake(next_x, next_y, next_z)
				|| makeRandomTurn()){

			delta_x = 0;
			delta_y = 0;
			delta_z = 0;

			// Pick a new random direction
			int r = rand() % 6;
			switch(r){
				case 0:
					delta_x = -1;
					break;
				case 1:
					delta_x = 1;
					break;
				case 2:
					delta_y = -1;
					break;
				case 3:
				default:
					delta_y = 1;
					break;
				case 4:
					delta_z = -1;
					break;
				case 5:
					delta_z = 1;
					break;
			}
		}
		else {
			break;
		}

		attempts++;
		if (attempts == 30){
			stuck = 40;
			delay = 20;
			return;
		}
	}

	// Move snake
	shuffleSnake();

	// Set new head
	snake_x[0] = snake_x[1] + delta_x;
	snake_y[0] = snake_y[1] + delta_y;
	snake_z[0] = snake_z[1] + delta_z;

	// Draw new snake
	drawSnakeInCube();
}
