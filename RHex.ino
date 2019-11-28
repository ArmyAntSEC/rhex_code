#include "Arduino.h"
#include "EncoderReader.h"
#include "MotorRegulator.h"
#include "MotorDriver.h"

#include <FixedPointsCommon.h>

int driverPinOne = 3;
int driverPinTwo = 5;

int encoderPinOne = 2;
int encoderPinTwo = 4;

int posPWMOutputPin =  10;
int rotationCounterInputPin =  13;

int lastLevelOne = 0;
long numberOfClicks = 0;
unsigned long millisBetweenWrite = 1000;
unsigned long millisForLastWrite = 0;

unsigned long microsBetweenUpdate = 1000;
unsigned long microsForLastUpdate = 0;


long loopIterationCount = 0;

SQ15x16 motorPositionRevs;
SQ15x16 motorPWM;

EncoderReader encoderReader( encoderPinOne, encoderPinTwo );
MotorRegulator motorRegulator;
MotorDriver motorDriver( driverPinOne, driverPinTwo );

int lastRotationCounterLevel = 0;
SQ15x16 wantedPosRevs = -0.5;

void setup() {
	motorDriver.initPins();
	encoderReader.initPins();

	pinMode(posPWMOutputPin, OUTPUT);
	pinMode(rotationCounterInputPin, INPUT);

	//Initialize the regulator.
	motorRegulator.setWantedPositionRevs( wantedPosRevs );

	//Initilaize the communication.
	Serial.begin(9600);
	Serial.println("Hello World again!");

}


void loop() {
	loopIterationCount++;

	/*
	motorDriver.setMotorPWM( 64 );
	int newRotationCounterLevel = digitalRead( rotationCounterInputPin  );
	if ( newRotationCounterLevel != lastRotationCounterLevel ) {
		Serial.println ("LAP!" );
		lastRotationCounterLevel = newRotationCounterLevel;
	}
	*/

	//We update the encoder value on each iteration
	encoderReader.step();
	motorPositionRevs = encoderReader.getLastMotorPositionRevs();
	int motorPosPWM = ((motorPositionRevs * 256).getInteger() % 256 + 256) % 256;


	//100 times per second, update the PWM values
	if ( micros() >= microsForLastUpdate + microsBetweenUpdate ) {
		microsForLastUpdate += microsBetweenUpdate;

		motorPositionRevs = encoderReader.getLastMotorPositionRevs();
		motorPWM = motorRegulator.getPWMValue(motorPositionRevs);

		motorDriver.setMotorPWM( motorPWM.getInteger() );


	}

	//Once per second, write some stats to serial.
	if ( millis() >= millisForLastWrite + millisBetweenWrite ) {
		millisForLastWrite += millisBetweenWrite;

		Serial.print ( "Wanted pos: ");
		Serial.print ( (float)wantedPosRevs, DEC );
		Serial.println ( " [revs]" );

		Serial.print ( "Motor Position: ");
		Serial.print ( (float)motorPositionRevs, DEC );
		Serial.println ( " [revs]" );

		Serial.print ( "Motor PWM: " );
		Serial.println ( (float)motorPWM, DEC );

		//analogWrite(posPWMOutputPin, motorPosPWM);

		//Serial.print ( "Pos PWM: " );
		//Serial.println ( motorPosPWM, DEC );

		Serial.print ( "Loops/s: " );
		Serial.println ( loopIterationCount/(millis()/1000), DEC );

	}

}
