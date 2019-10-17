#include "Arduino.h"
#include "EncoderReader.h"

EncoderReader::EncoderReader()
{
	this->lastValueOne = 0;
	this->lastValueTwo = 0;
	this->lastMotorPositionStep = 0;

	this->transitionsMatrix[1][1][0][1] = 1;
	this->transitionsMatrix[0][1][0][0] = 1;
	this->transitionsMatrix[0][0][1][0] = 1;
	this->transitionsMatrix[1][0][1][1] = 1;
	this->transitionsMatrix[1][1][1][0] = -1;
	this->transitionsMatrix[1][0][0][0] = -1;
	this->transitionsMatrix[0][0][0][1] = -1;
	this->transitionsMatrix[0][1][1][1] = -1;
}


void EncoderReader::step( int valueOne, int valueTwo )
{
	if ( valueOne != this->lastValueOne || valueTwo != this->lastValueTwo ) {
		int stepDir = this->transitionsMatrix[this->lastValueOne][this->lastValueTwo][valueOne][valueTwo];

		this->lastValueOne = valueOne;
		this->lastValueTwo = valueTwo;

		this->lastMotorPositionStep = this->lastMotorPositionStep + stepDir;
	}
}


long EncoderReader::getLastMotorPositionStep()
{
	return this->lastMotorPositionStep;
}


int EncoderReader::getLastValueOne()
{
	return this->lastValueOne;
}

int EncoderReader::getLastValueTwo()
{
	return this->lastValueTwo;
}
