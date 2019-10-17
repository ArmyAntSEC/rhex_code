#include "arduino.h"
#include "MotorRegulator.h"


MotorRegulator::MotorRegulator() {

}


void MotorRegulator::setWantedPosition( SQ15x16 wantedPos ) {
	this->wantedPos = wantedPos;
}


SQ15x16 MotorRegulator::getPWMValue( SQ15x16 position )
{
	SQ15x16 delta = this->wantedPos - position;
	SQ15x16 pwmValue = this->P * delta;
    pwmValue = max(min(pwmValue,255),-255);
    return pwmValue;
}


