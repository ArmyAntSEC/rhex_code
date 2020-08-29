/*
 * MotorSinWaver.cpp
 *
 *  Created on: 17 aug. 2020
 *      Author: Daniel
 */

#include "MotorSinWaver.h"
#include <Arduino.h>

MotorSinWaver::MotorSinWaver(MotorStateHandler* _handler, MotorDriver* _driver ):
		MotorStateHandlerImpl( _handler, _driver ), startTime(0)
 {
}

void MotorSinWaver::run(unsigned long int now) {
	if ( startTime == 0 ) {
		Serial.println ( "MotorSinWaver: Called for the first time.");
		startTime = now;
	}

	//Have the leg wave a simple sin wave motion. Open loop controll.
	unsigned int timeDiff = now - startTime;
	unsigned int period = 1000; //Millis
	double timeDiffPeriod = timeDiff % period;

	//Compute the sine of the time diff.
	int speed = (int)(255*sin(2*M_PI*timeDiffPeriod/1000));
	driver->setMotorPWM(speed);
}
