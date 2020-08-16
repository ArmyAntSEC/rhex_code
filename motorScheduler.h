/*
 * motorScheduler.h
 *
 *  Created on: 1 nov. 2019
 *      Author: Daniel
 */

#ifndef MOTORSCHEDULER_H_
#define MOTORSCHEDULER_H_

#include "RecurringTask.h"
#include "MotorController.h"

class MotorScheduler : public RecurringTask { // @suppress("Class has a virtual method and non-virtual destructor")
private:
    const double cycleTimeSeconds;
    const double slowTime;
    const double slowPhase;
    const double angleOffset;

    double slowTimeDelta;
    double angleOffsetDelta;

    double wantedShaftPosRev;
    MotorController * const controller;

    double interp1( int xlen, double x[], double y[], double xq );
public:
	MotorScheduler(unsigned long int _rate, MotorController * const _controller );

	virtual void run(unsigned long int now);

	void setAngleOffsetDelta(double angleOffsetDelta) {
		this->angleOffsetDelta = angleOffsetDelta;
	}

	void setSlowTimeDelta(double slowTimeDelta) {
		this->slowTimeDelta = slowTimeDelta;
	}
};

#endif /* MOTORSCHEDULER_H_ */
