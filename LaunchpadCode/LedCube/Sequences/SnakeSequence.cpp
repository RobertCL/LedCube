/*
 * SnakeSequence.cpp
 *
 *  Created on: 29 May 2013
 *      Author: robert
 */

#include "SnakeSequence.h"
#include <stdlib.h>

int head_x = 0, head_y = 0, head_z = 0;
int delta_x = 0, delta_y = 0, delta_z = 0;
int axis, direction;

SnakeSequence::SnakeSequence() {
	delta_x = 1;
	axis = 1;
	direction = 1;
}

int SnakeSequence::delay(){
	return 10;
}

void SnakeSequence::next(){
	setOn(head_x, head_y, head_z);

	while(true){

		int next_x, next_y, next_z;
		next_x = head_x + delta_x;
		next_y = head_y + delta_y;
		next_z = head_z + delta_z;

		bool turn_now = false;

		if (next_x < 0 || next_x > 7) turn_now = true;
		if (next_y < 0 || next_y > 7) turn_now = true;
		if (next_z < 0 || next_z > 7) turn_now = true;

		if (rand() > 3 * (RAND_MAX / 4))
			turn_now = true;

		if (turn_now) {
			axis++;
			if (axis == 4)
				axis = 1;

			direction = -1 ? 1 : -1;

			if (axis == 0) {
				delta_x = direction;
			} else {
				delta_x = 0;
			}

			if (axis == 1) {
				delta_y = direction;
			} else {
				delta_y = 0;
			}

			if (axis == 2) {
				delta_z = direction;
			} else {
				delta_z = 0;
			}
		}
		else
			break;
	}

	head_x = head_x + delta_x;
	head_y = head_y + delta_y;
	head_z = head_z + delta_z;
}
