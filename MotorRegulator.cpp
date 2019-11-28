#include "arduino.h"
#include "MotorRegulator.h"


MotorRegulator::MotorRegulator() {

}


void MotorRegulator::setWantedPositionRevs( SQ15x16 wantedPosRevs ) {
	this->wantedPosRevs = wantedPosRevs;
}


SQ15x16 MotorRegulator::getPWMValue( SQ15x16 currentPositionRevs )
{
	SQ15x16 delta = this->wantedPosRevs - currentPositionRevs ;

	if ( this->lastDelta > 1 ) {
		this->lastDelta  = this->lastDelta - 1;
	}
	SQ15x16 pwmValue = this->P * this->lastDelta + this->D * (delta - this->lastDelta);
    pwmValue = max(min(pwmValue,64),-64);

    this->lastDelta = delta;

    return pwmFilter.step(pwmValue);

}


