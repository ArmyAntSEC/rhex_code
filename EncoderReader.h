void testFun();

#ifndef __ENCODER_READER__
#define __ENCODER_READER__

#include <FixedPointsCommon.h>

class EncoderReader
{
private:
	int lastValueOne;
	int lastValueTwo;
	long lastMotorPositionStep;
	int transitionsMatrix[2][2][2][2];
	const int stepsPerRevolution = 48*75;

	int encoderPinOne;
	int encoderPinTwo;
public:
	EncoderReader( int encoderPinOne, int encoderPinTwo );
	void initPins();
	void step();
	long getLastMotorPositionSteps();
	SQ15x16 getLastMotorPositionRevs();
	int getLastValueOne();
	int getLastValueTwo();
};

#endif
