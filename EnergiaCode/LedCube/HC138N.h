/*
 * HC138N.h
 *
 *  Created on: 1 Apr 2013
 *      Author: robert
 */

#ifndef HC138N_H_
#define HC138N_H_

class HC138N {

public:
	HC138N(long port);
	virtual ~HC138N();

        void init();
	void set(unsigned char value);
	void setp(unsigned char value);
	void pulse();
	void enable();
	void disable();

private:
	long _port;

};

#endif /* HC138N_H_ */
