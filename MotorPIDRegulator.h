/*
 * MotorPDRegulator.h
 *
 *  Created on: 18 aug. 2020
 *      Author: Daniel
 */

#ifndef MOTORPIDREGULATOR_H_
#define MOTORPIDREGULATOR_H_

#include "MotorStateHandlerImpl.h"
#include "Encoder.h"
#include "PID.h"

class MotorPIDRegulator: public MotorStateHandlerImpl { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	MotorPIDRegulator(MotorStateHandler* _handler, MotorDriver* _driver, Encoder* _encoder, PID* _pid );
	virtual void run(unsigned long int now);
	void setWantedPositionRevs( float _setPointRevs );
private:
	double angleDifference( double angle1, double angle2 );
	Encoder* encoder;
	PID* pid;
	double setPointRad;
};

#endif /* MOTORPIDREGULATOR_H_ */
