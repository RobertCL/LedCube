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
	delay = 10;
	stuck = 0;

	for (int i = 0; i < MAX_SNAKE_LEN; i++){
		snake_x[i] = 0;
		snake_y[i] = 0;
		snake_z[i] = 0;
	}
	snakeLen = 1;
	growBy = 4;

	delta_x = 1;
	delta_y = 0;
	delta_z = 0;

	for (int i = 0; i < 6; i++) {
		food_x[i] = rand() % 8;
		food_y[i] = rand() % 8;
		food_z[i] = rand() % 8;
	}
	foodCount = 5;

	drawSnakeInCube();
	drawFoodInCube();
}

void Snake2Sequence::drawSnakeInCube(){
	cubeOff();
	for (int i = 0; i < snakeLen; i++){
		setOn(snake_x[i], snake_y[i], snake_z[i]);
	}
}

void Snake2Sequence::drawFoodInCube(){
	for (int i = 0; i < foodCount; i++){
		setOn(food_x[i], food_y[i], food_z[i]);
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

short Snake2Sequence::isFood(char x, char y, char z){
	for (char i = 0; i < foodCount; i++)
		if (food_x[i] == x && food_y[i] == y && food_z[i] == z)
			return i;

	return -1;
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
		if (attempts == 90){
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

	// See if we've eaten anything
	short food = isFood(snake_x[0], snake_y[0], snake_z[0]);
	if (food >= 0){
		// Mmm, food
		// grow
		growBy += 3;
		while (snakeLen + growBy > MAX_SNAKE_LEN) { growBy--; }
		// speed up
		delay--;
		if (delay < 1) delay = 1;

		// Replace with more food
		food_x[food] = rand() % 8;
		food_y[food] = rand() % 8;
		food_z[food] = rand() % 8;
	}

	// Draw new snake
	drawSnakeInCube();
	drawFoodInCube();
}
