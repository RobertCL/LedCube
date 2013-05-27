/*
 * CubeTracker.h
 *
 *  Created on: 27 May 2013
 *      Author: robert
 */

#ifndef CUBETRACKER_H_
#define CUBETRACKER_H_

class CubeTracker {
public:
	CubeTracker(int x, int y, int z, int size, int xp, int yp, int zp);

	int x;
	int y;
	int z;
	int size;

	void move();

private:
	int xp;
	int yp;
	int zp;
};

#endif /* CUBETRACKER_H_ */
