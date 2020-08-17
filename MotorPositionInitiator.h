/*
 * MotorPositionInitiator.h
 *
 *  Created on: 15 aug. 2020
 *      Author: Daniel
 */

#ifndef MOTORPOSITIONINITIATOR_H_
#define MOTORPOSITIONINITIATOR_H_

#include "MotorStateHandlerImpl.h"
#include "MotorDriver.h"
#include "OptoBreaker.h"

class MotorPositionInitiator: public MotorStateHandlerImpl { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	MotorPositionInitiator(  MotorStateHandler* _handler, MotorDriver* _driver, OptoBreaker* _breaker );
	virtual void run(unsigned long int now);
private:
	enum State { NEW, MOVING, DONE };
	State state;
};

#endif /* MOTORPOSITIONINITIATOR_H_ */
