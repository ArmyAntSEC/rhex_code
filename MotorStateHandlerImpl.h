/*
 * MotorStateHandlerImpl.h
 *
 *  Created on: 17 aug. 2020
 *      Author: Daniel
 */

#ifndef MOTORSTATEHANDLERIMPL_H_
#define MOTORSTATEHANDLERIMPL_H_

#include "MotorDriver.h"

class MotorStateHandler;

class MotorStateHandlerImpl { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	MotorStateHandlerImpl( MotorStateHandler* _handler, MotorDriver* _driver ):
	handler(_handler), driver(_driver) {}
	virtual void run(unsigned long int now) = 0;
protected:
	MotorStateHandler* handler;
	MotorDriver* driver;
};

#include "MotorStateHandler.h"

#endif /* MOTORSTATEHANDLERIMPL_H_ */
