/*
 * MotorStateHandler.h
 *
 *  Created on: 16 aug. 2020
 *      Author: Daniel
 */

#ifndef MOTORSTATEHANDLER_H_
#define MOTORSTATEHANDLER_H_

#include "RecurringTask.h"
#include "MotorPositionInitiator.h"

class MotorStateHandler: public RecurringTask { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	MotorStateHandler(unsigned long int rate, MotorPositionInitiator* _state );
	virtual void run(unsigned long int now);
private:
	MotorPositionInitiator* state;
};

#endif /* MOTORSTATEHANDLER_H_ */
