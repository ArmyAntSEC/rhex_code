/*
 * MotorRegulator.h
 *
 *  Created on: 17 okt. 2019
 *      Author: Daniel
 */

#ifndef MOTORREGULATOR_H_
#define MOTORREGULATOR_H_

#include <FixedPoints.h>
#include <FixedPointsCommon.h>

class MotorRegulator {
private:
	const SQ15x16 P = 100;
	const SQ15x16 D = 0;
	const int Fmax = 255;
	const int Fmin = -255;

	SQ15x16 wantedPos = 1000;
	SQ15x16 lastPosition = 0;

public:
	MotorRegulator();
	void setWantedPosition( SQ15x16 wantedPosition );
	SQ15x16 getPWMValue( SQ15x16 position );
};

#endif
