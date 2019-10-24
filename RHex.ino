#include "Arduino.h"
#include "EncoderReader.h"
#include "MotorRegulator.h"
#include "MotorDriver.h"

#include <FixedPointsCommon.h>

int driverPinOne = 3;
int driverPinTwo = 5;

int encoderPinOne = 2;
int encoderPinTwo = 4;

int lastLevelOne = 0;
long numberOfClicks = 0;
unsigned long millisBetweenWrite = 1000;
unsigned long millisForLastWrite = 0;

unsigned long millisBetweenUpdate = 10;
unsigned long millisForLastUpdate = 0;


long loopIterationCount = 0;

EncoderReader encoderReader;
MotorRegulator motorRegulator;
MotorDriver motorDriver( driverPinOne, driverPinTwo );

void setup() {
	//Driver pins
	pinMode(driverPinOne, OUTPUT);
	pinMode(driverPinTwo, OUTPUT);
	analogWrite(driverPinOne, 0); //Set to 0-255 to select speed.
	analogWrite(driverPinTwo, 0); //Set to 0-255 to select speed.

	//Encoder pins
	pinMode( encoderPinOne, INPUT );
	pinMode( encoderPinTwo, INPUT );

	//Initialize the regulator.
	motorRegulator.setWantedPositionRevs( -0.8 );

	//Initilaize the communication.
	Serial.begin(9600);
	Serial.println("Hello World again!");

	int temp = 10;
	SQ15x16 temp2 = temp;
	Serial.print( temp2.getInteger(), DEC );


}

SQ15x16 motorPositionRevs;
SQ15x16 motorPWM;

void loop() {


	//We update the encoder value on each iteration
	int encoderValueOne = digitalRead( encoderPinOne );
	int encoderValueTwo = digitalRead( encoderPinTwo );
	encoderReader.step( encoderValueOne, encoderValueTwo );

	//100 times per second, update the PWM values
	if ( millis() >= millisForLastUpdate + millisBetweenUpdate ) {
		millisForLastUpdate += millisBetweenUpdate;

		motorPositionRevs = encoderReader.getLastMotorPositionRevs();
		motorPWM = motorRegulator.getPWMValue(motorPositionRevs);

		motorDriver.setMotorPWM( motorPWM.getInteger() );

	}

	//Once per second, write some stats to serial.
	if ( millis() >= millisForLastWrite + millisBetweenWrite ) {
		millisForLastWrite += millisBetweenWrite;

		Serial.print ( "Motor Position: ");
		Serial.print ( (float)motorPositionRevs, DEC );
		Serial.println ( " [revs]" );

		Serial.print ( "Motor PWM: " );
		Serial.println ( (float)motorPWM, DEC );
	}
}
