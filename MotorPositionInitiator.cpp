/*
 * MotorPositionInitiator.cpp
 *
 *  Created on: 15 aug. 2020
 *      Author: Daniel
 */

#include "MotorPositionInitiator.h"
#include <Arduino.h>

MotorPositionInitiator::MotorPositionInitiator(MotorStateHandler* _handler, MotorDriver* _driver, OptoBreaker* _breaker ):
	MotorStateHandlerImpl(_handler, _driver ), state(NEW), breaker(_breaker)
{}

void MotorPositionInitiator::run(unsigned long int) {
	switch ( state ) {
	case NEW:
		Serial.println ( "Intiator: State is NEW." );
		driver->setMotorPWM(64);
		if ( !breaker->read() ) {
			//In case we are at the opening allready, we need to move off of it to then get a sharp edge.
			state = MOVING;
			Serial.println ( "Initiator: Changing state to MOVING" );
		}

		break;

	case MOVING:
		Serial.println ( "Initiator: State is MOVING." );
		if ( breaker->read() ) {
			driver->setMotorPWM(0);
			state = DONE;
			handler->startMainLoop();
			Serial.println ( "Initiator: Edge found. Done." );
		}
		break;
	default:
		Serial.print ( "Initiator: Assertion failed. State should never happen." );
	}
}
