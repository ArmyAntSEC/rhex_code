/*
 * MotorController.h
 *
 *  Created on: 9 juli 2020
 *      Author: Daniel
 */

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "TimedTask.h"
#include <encoder.h>

#include "PID.h"
#include "MotorDriver.h"

class MotorController: public TaskScheduler::TimedTask { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	MotorController(unsigned int _rate, unsigned int encoderPin1, unsigned int encoderPin2, //
			unsigned int driverPin1, unsigned int driverPin2 );
	void init();
	virtual void run(unsigned long int /*now*/);

	void setMotorWantedPos(double motorWantedPos) {
		this->motorWantedPos = motorWantedPos;
	}

private:
	Encoder encoder;
	MotorDriver driver;
	unsigned int rate;
	double motorPos;
	double motorPWM;
	double motorWantedPos;
	double P;
	double I;
	double D;
	PID pid;
};

#endif /* MOTORCONTROLLER_H_ */
