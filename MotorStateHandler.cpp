/*
 * MotorStateHandler.cpp
 *
 *  Created on: 16 aug. 2020
 *      Author: Daniel
 */

#include "MotorStateHandler.h"

MotorStateHandler::MotorStateHandler( unsigned long int rate, MotorPositionInitiator* _state ):
		RecurringTask(rate)
{
	state = _state;
}

void MotorStateHandler::run(unsigned long int now) {
	RecurringTask::run(now);

	state->run(now);

}
