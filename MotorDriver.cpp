/*
 * MotorDriver.cpp
 *
 *  Created on: 24 okt. 2019
 *      Author: Daniel
 */
#include <Arduino.h>
#include "MotorDriver.h"


MotorDriver::MotorDriver(int _driverPinOne, int _driverPinTwo, int _driverPinPWM ):
driverPinOne(_driverPinOne), driverPinTwo(_driverPinTwo), driverPinPWM(_driverPinPWM)
{}

void MotorDriver::init() {
	pinMode(this->driverPinOne, OUTPUT);
	pinMode(this->driverPinTwo, OUTPUT);
	this->setMotorPWM(0);
}

void MotorDriver::setMotorPWM( int motorPWM )
{
	//Stop drivers if power is slow.
	if ( abs(motorPWM) < 20 ) {
		motorPWM = 0;
	}

	if ( motorPWM <= 0 ) {
		digitalWrite ( this->driverPinTwo, LOW);
		digitalWrite ( this->driverPinOne, HIGH);
		analogWrite ( this->driverPinPWM, abs(motorPWM) );
	} else {
		digitalWrite ( this->driverPinTwo, HIGH);
		digitalWrite ( this->driverPinOne, LOW);
		analogWrite ( this->driverPinPWM, abs(motorPWM) );
	}
}
