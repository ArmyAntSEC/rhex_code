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
	MotorStateHandler(unsigned long int rate);
	virtual void run(unsigned long int now);
	void startInitiator();
	void startMainLoop();
	void setInitiator(MotorStateHandlerImpl* initiator);
	void setMainLoop(MotorStateHandlerImpl* mainLoop);

private:
	MotorStateHandlerImpl* initiator;
	MotorStateHandlerImpl* mainLoop;
	MotorStateHandlerImpl* currentState;
};

#endif /* MOTORSTATEHANDLER_H_ */
