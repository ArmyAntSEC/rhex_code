/*
 * OptoBreaker.h
 *
 *  Created on: 15 aug. 2020
 *      Author: Daniel
 */

#ifndef OPTOBREAKER_H_
#define OPTOBREAKER_H_

class OptoBreaker {
public:
	OptoBreaker(int _pin);
	bool read();
private:
	int pin;
};

#endif /* OPTOBREAKER_H_ */
