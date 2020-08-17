/*
 * MotorStateHandler.cpp
 *
 *  Created on: 16 aug. 2020
 *      Author: Daniel
 */

#include "MotorStateHandler.h"
#include "Arduino.h"

MotorStateHandler::MotorStateHandler( unsigned long int rate ):
				RecurringTask(rate), initiator(0), mainLoop(0), currentState(0)
{
}

void MotorStateHandler::startInitiator() {
	currentState = initiator;
}
void MotorStateHandler::startMainLoop() {
	currentState = mainLoop;
}

void MotorStateHandler::setInitiator(MotorStateHandlerImpl* initiator) {
	this->initiator = initiator;
}

void MotorStateHandler::setMainLoop(MotorStateHandlerImpl* mainLoop) {
	this->mainLoop = mainLoop;
}


void MotorStateHandler::run(unsigned long int now) {
	RecurringTask::run(now);
	if ( currentState != 0 ) {
		currentState->run(now);
	}

}
