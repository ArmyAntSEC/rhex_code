/*
 * motorScheduler.h
 *
 *  Created on: 1 nov. 2019
 *      Author: Daniel
 */

#ifndef MOTORSCHEDULER_H_
#define MOTORSCHEDULER_H_

#include <FixedPointsCommon.h>

class MotorScheduler {
private:
	SQ15x16 currentSpeedRevsPerSecond;
	SQ15x16 lastWantedPos;
	SQ15x16 lastStepPhase;
	long lastTimestampMicros;

	SQ15x16 convertPhaseToPosRevs( SQ15x16 phase );

public:
	MotorScheduler();
	void setSpeed( SQ15x16 wantedSpeedRevsPerSecond );
	SQ15x16 step( long microsSinceStart );

};

#endif /* MOTORSCHEDULER_H_ */
