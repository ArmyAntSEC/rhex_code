void testFun();

#ifndef __ENCODER_READER__
#define __ENCODER_READER__

class EncoderReader
{
private:
	int lastValueOne;
	int lastValueTwo;
	long lastMotorPositionStep;
	int transitionsMatrix[2][2][2][2];
public:
	EncoderReader();
	void step( int valueOne, int valueTwo );
	long getLastMotorPositionStep();
	int getLastValueOne();
	int getLastValueTwo();
};

#endif
