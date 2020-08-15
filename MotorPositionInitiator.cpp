/*
 * MotorPositionInitiator.cpp
 *
 *  Created on: 15 aug. 2020
 *      Author: Daniel
 */

#include "MotorPositionInitiator.h"
#include <Arduino.h>

MotorPositionInitiator::MotorPositionInitiator(unsigned int _rate, MotorDriver* _driver, OptoBreaker* _breaker ):
		RecurringTask(_rate), state(NEW), driver(_driver), breaker(_breaker)
{}

void MotorPositionInitiator::run(unsigned long int now) {
	RecurringTask::run(now);

	switch ( state ) {
	case NEW:
		driver->setMotorPWM(64);
		if ( !breaker->read() ) {
			//In case we are at the opening allready, we need to move off of it to then get a sharp edge.
			state = MOVING;
		}
		Serial.println ( "Intiator: Started" );
		break;

	case MOVING:
		if ( breaker->read() ) {
			driver->setMotorPWM(0);
			state = DONE;
			this->stop();
			Serial.println ( "Initiator: Edge found. Done." );
		}
		break;
	default:
		Serial.print ( "Initiator: Assertion failed. State should never happen." );
	}
}
