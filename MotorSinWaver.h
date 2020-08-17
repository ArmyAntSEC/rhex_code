/*
 * MotorSinWaver.h
 *
 *  Created on: 17 aug. 2020
 *      Author: Daniel
 */

#ifndef MOTORSINWAVER_H_
#define MOTORSINWAVER_H_

#include "MotorStateHandlerImpl.h"

class MotorSinWaver: public MotorStateHandlerImpl { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	MotorSinWaver(MotorStateHandler* _handler, MotorDriver* _driver, OptoBreaker* _breaker);
	virtual void run(unsigned long int now);
private:
	unsigned long int startTime;
};

#endif /* MOTORSINWAVER_H_ */
