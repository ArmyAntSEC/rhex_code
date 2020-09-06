/*
 * MotorPDRegulator.cpp
 *
 *  Created on: 18 aug. 2020
 *      Author: Daniel
 */

#include "MotorPIDRegulator.h"
#include "Arduino.h"

MotorPIDRegulator::MotorPIDRegulator ( MotorStateHandler* _handler, MotorDriver* _driver, Encoder* _encoder, PID* _pid ):
	MotorStateHandlerImpl(_handler, _driver), encoder(_encoder), pid(_pid), setPointRev(0)
{
}

void MotorPIDRegulator::init() {
	Serial.println( "Regulator: Reseting the encoder." );
	//Make sure encoder things we are at position 0.
	long int pos = this->encoder->readAndReset();
	Serial.print( "Old position: " );
	Serial.print ( pos );
	pos = this->encoder->read();
	Serial.print( " New position: " );
	Serial.println ( pos );
}

void MotorPIDRegulator::setWantedPositionRev( float _setPointRev) {
	this->setPointRev = _setPointRev;
}

void MotorPIDRegulator::run(unsigned long int) {
	long int currentPositionClicks = this->encoder->read();

	//And compute the current position in radians
	double currentPositionRev =  (double)currentPositionClicks/3591.84; //Convert clicks to rotations.

	double PwmValue = this->pid->Compute(currentPositionRev, this->setPointRev );

	this->driver->setMotorPWM((int)PwmValue);
	Serial.print ("Regulator: Step: " );
	Serial.print ( currentPositionClicks );
	Serial.print ( ", " );
	Serial.print ( currentPositionRev );
	Serial.print ( ", " );
	Serial.print ( this->setPointRev );
	Serial.print ( ", " );
	Serial.println ( PwmValue );

}
