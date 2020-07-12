/*
 * motorScheduler.cpp
 *
 *  Created on: 1 nov. 2019
 *      Author: Daniel
 */

#include "motorScheduler.h"

#define PI 3.1415926535897932384626433832795
#include <math.h>

MotorScheduler::MotorScheduler( unsigned long int _rate, MotorController * const _controller ) :
TaskScheduler::RecurringTask( _rate ), cycleTimeSeconds(2), slowTime(cycleTimeSeconds/2),
slowPhase(2*PI/3), angleOffset(0), controller(_controller)
{
	this->slowTimeDelta = 0;
	this->angleOffsetDelta = 0;
	this->wantedShaftPosRev = 0;
}

double MotorScheduler::interp1(int xlen, double x[], double y[], double xq) {
	//Note: X must be strictly monotonically increasing.<

	//Check that we are in range
	if ( xq < x[0] || xq > x[xlen-1] ) {
		return 1.0/0.0;
	}

	//Now find what segment we are in
	int segment = 0;
	while ( xq > x[segment+1] ) { segment++; }

	//Compute the start ane endpoints of the current segment.
	double x0 = x[segment];
	double x1 = x[segment+1];
	double y0 = y[segment];
	double y1 = y[segment+1];

	//Compute the relative position within the segment in x
	double xt = (xq - x0)/(x1-x0);

	//Compute the Y postion to return
	double yRet = y0 + (y1-y0)*xt;

	return yRet;
}

void MotorScheduler::run(unsigned long int now) {
	RecurringTask::run(now);

	double locationInTimeLoop = fmod(now,this->cycleTimeSeconds);
	const int arrayLength = 4;
	double time[arrayLength] = {0,
			this->cycleTimeSeconds/2.0 - (this->slowTime + this->slowTimeDelta)/2.0,
			this->cycleTimeSeconds/2.0 + (this->slowTime + this->slowTimeDelta)/2.0,
			this->cycleTimeSeconds
	};

	double angle[arrayLength] = { -PI,
			-this->slowPhase/2,
			this->slowPhase/2,
			PI
	};

	double wantedShaftPosAngle = this->interp1( arrayLength, time,angle, locationInTimeLoop);
	double wantedShaftPosRev = wantedShaftPosAngle/(2.0*PI);

	//Pass the information to the registered motor controller
	controller->setShaftPosRev(wantedShaftPosRev);
}
