/*
 * MotorPDRegulator.cpp
 *
 *  Created on: 18 aug. 2020
 *      Author: Daniel
 */

#include "MotorPIDRegulator.h"

MotorPIDRegulator::MotorPIDRegulator ( MotorStateHandler* _handler, MotorDriver* _driver, Encoder* _encoder, PID* _pid ):
	MotorStateHandlerImpl(_handler, _driver), encoder(_encoder), pid(_pid), setPointRad(0)
{
}

void MotorPIDRegulator::setWantedPositionRevs( float _setPointRad) {
	this->setPointRad = _setPointRad;
}

void MotorPIDRegulator::run(unsigned long int now) {
	long int currentPositionClicks = this->encoder->read();
	//Compute the number of clicks into the current revolution.
	long int currentPositionClicksSingleRev = currentPositionClicks - (5172372*(currentPositionClicks*144)/5172372)/144;

	//And compute the current position in radians
	double currentPositionRad =  (double)currentPositionClicksSingleRev*5172372.0/144.0*2*M_PI;

	double PwmValue = this->pid->Compute(currentPositionRad, this->setPointRad );

	this->driver->setMotorPWM((int)PwmValue);
}
