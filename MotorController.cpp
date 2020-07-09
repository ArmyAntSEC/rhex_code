/*
 * MotorController.cpp
 *
 *  Created on: 9 juli 2020
 *      Author: Daniel
 */

#include "MotorController.h"
#include <arduino.h>

MotorController::MotorController(unsigned int _rate, unsigned int encoderPin1, unsigned int encoderPin2, //
		unsigned int driverPin1, unsigned int driverPin2 )
	: TimedTask(millis()), encoder(encoderPin1, encoderPin2), //
	  driver( driverPin1, driverPin2 ), //
	  rate(_rate), motorPos(0), motorPWM(0), motorWantedPos(0), //
	  P(0), I(0), D(0), pid( P, I, D, DIRECT, _rate)
{
	pid.SetSampleTime(rate);
}

void MotorController::init() {
	driver.init();
	motorPos = encoder.read();
	pid.init(motorPos);
}

void MotorController::run(unsigned long int /*now*/) {
	motorPos = encoder.read();
	motorPos = pid.Compute(motorPos, motorWantedPos);
	driver.setMotorPWM(motorPWM);
}
