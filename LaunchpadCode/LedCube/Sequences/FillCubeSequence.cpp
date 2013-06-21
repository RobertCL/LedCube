/*
 * FillCubeSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "FillCubeSequence.h"

FillCubeSequence::FillCubeSequence(char (&ref)[8][8]) : Sequence(ref) {
	x=0;
	y=0;
	delay = 1;
}

void FillCubeSequence::next(){
	if ((*cube)[y][x] == 0x00)
		(*cube)[y][x] = 0x01;
	else
	{
		(*cube)[y][x] = ((*cube)[y][x] << 1) + 1;

		if ((*cube)[y][x] == 0xFF)
		{
			x++;
			if (x == 8)
			{
				x = 0;
				y++;
				if (y == 8)
				{
					y = 0;

					// reset to zero
					for (int i=0; i<8;i++)
						for (int j=0;j<8;j++)
							(*cube)[i][j] = 0x00;

				}
			}
		}
	}
}
