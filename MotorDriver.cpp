/*
 * MotorDriver.cpp
 *
 *  Created on: 24 okt. 2019
 *      Author: Daniel
 */
#include <Arduino.h>
#include "MotorDriver.h"


MotorDriver::MotorDriver(int driverPinOne, int driverPinTwo )
{
	this->driverPinOne = driverPinOne;
	this->driverPinTwo = driverPinTwo;
}

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
		analogWrite(this->driverPinTwo, 0);
		analogWrite(this->driverPinOne, abs(motorPWM) );
	} else {
		analogWrite(this->driverPinTwo, abs(motorPWM) );
		analogWrite(this->driverPinOne, 0);
	}
}
