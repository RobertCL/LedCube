/*
 * TranslationTestSequence.cpp
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#include "TranslationTestSequence.h"

TranslationTestSequence::TranslationTestSequence(char (&ref)[8][8]) : Sequence(ref) {}

void TranslationTestSequence::initialize(){
	Sequence::initialize();
	plane = 0;
	drawPlaneNext = true;
	count = 0;
	dir = 1;
	delay = 4;
	runCycles = 0;
	name = "Translation";
}

void TranslationTestSequence::clearAndDrawInitialPlane(){
	cubeOff();

	switch(plane){
		case 0:
		case 1:
			DrawXYPlane(0);
			break;

		case 2:
		case 3:
			DrawXZPlane(0);
			break;

		case 4:
		case 5:
			DrawYZPlane(0);
			break;
	}
}

void TranslationTestSequence::next(){
	if (drawPlaneNext)
	{
		clearAndDrawInitialPlane();
		drawPlaneNext = false;
	}
	else // move plane
	{
		switch (plane){
			case 0:
			case 1:
				Translate(0, 0, dir);
				break;

			case 2:
			case 3:
				Translate(0, dir, 0);
				break;

			case 4:
			case 5:
				Translate(dir, 0, 0);
				break;
		}

		count += dir;
		if (count == 7)
			dir = -1;
		else if (count == 0)
		{
			dir = 1;

			plane++;
			if (plane == 6) finished = true;
			drawPlaneNext = true;
		}
	}
}
