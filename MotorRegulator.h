/*
 * MotorRegulator.h
 *
 *  Created on: 17 okt. 2019
 *      Author: Daniel
 */

#ifndef MOTORREGULATOR_H_
#define MOTORREGULATOR_H_


#include <FixedPointsCommon.h>
#include "FIRFilter.h"

class MotorRegulator {
private:
	const SQ15x16 P = 4000;
	const SQ15x16 D = 0;
	const int Fmax = 255;
	const int Fmin = -255;

	SQ15x16 wantedPosRevs = 0;
	SQ15x16 lastPositionRevs = 0;
	SQ15x16 lastDelta = 0;

	FIRFilter pwmFilter = FIRFilter( 0.01 );

public:
	MotorRegulator();
	void setWantedPositionRevs( SQ15x16 wantedPositionRevs );
	SQ15x16 getPWMValue( SQ15x16 currentPositionRevs );
};

#endif
