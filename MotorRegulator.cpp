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
	if ( delta > 0.5 ) {
		delta = delta - 1;
	}
	SQ15x16 pwmValue = this->P * delta;
    pwmValue = max(min(pwmValue,255),-255);
    return pwmValue;
}


