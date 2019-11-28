/*
 * motorScheduler.cpp
 *
 *  Created on: 1 nov. 2019
 *      Author: Daniel
 */

#include "motorScheduler.h"

/*
 * 	SQ15X16 currentSpeedRevsPerSecond;
	SQ15X16 lastWantedPos;
	SQ15X16 laststepPhase;
	long lastTimestampMicros;
 *
 */

MotorScheduler::MotorScheduler() {
	this->currentSpeedRevsPerSecond = 0;
	this->lastWantedPos = 0;
	this->lastStepPhase = 0;
	this->lastTimestampMicros = 0;
}

void MotorScheduler::setSpeed( SQ15x16 wantedSpeedRevsPerSecond )
{
	this->currentSpeedRevsPerSecond = wantedSpeedRevsPerSecond;
}

SQ15x16 MotorScheduler::step( long microsSinceStart )
{
	long timeDelta = microsSinceStart - this->lastTimestampMicros;
	SQ15x16 phaseDelta = this->currentSpeedRevsPerSecond * timeDelta / 1e6;
	SQ15x16 newPhase = this->lastStepPhase + phaseDelta;
	SQ15x16 newPos = this->convertPhaseToPosRevs ( newPhase );
	this->lastWantedPos = newPos;
	this->lastStepPhase = newPhase;
	return newPos;
}

SQ15x16 MotorScheduler::convertPhaseToPosRevs( SQ15x16 phase )
{
	//Make sure phase is between 0 and 1;
	phase = phase - floorFixed( phase );

	if ( phase < 0.5 )
		return phase / 2;
	else
		return (phase - 0.5) * 3 / 2 + 0.25;

}
