#include "Arduino.h"
#include "EncoderReader.h"

int driverPinOne = 3;
int driverPinTwo = 5;

int encoderPinOne = 2;
int encoderPinTwo = 4;

int lastLevelOne = 0;
long numberOfClicks = 0;
unsigned long millisBetweenWrite = 100;
unsigned long millisForLastWrite = 0;

long loopIterationCount = 0;

EncoderReader encoderReader;

void setup() {
  //Driver pins
  pinMode(driverPinOne, OUTPUT);
  pinMode(driverPinTwo, OUTPUT);
  digitalWrite(driverPinOne, 0); //Set to 1 to ground one input
  analogWrite(driverPinTwo, 128); //Set to 0-255 to select speed.

  //Encoder pins
  pinMode( encoderPinOne, INPUT );
  pinMode( encoderPinTwo, INPUT );

  Serial.begin(9600);
  Serial.println("Hello World again!");
}

void loop() {
  //Read the encoder value and count the transitions.
  int encoderValueOne = digitalRead( encoderPinOne );
  int encoderValueTwo = digitalRead( encoderPinTwo );
  if (encoderValueOne != lastLevelOne )
  {
    lastLevelOne = encoderValueOne;
    numberOfClicks++;
  }

  encoderReader.step( encoderValueOne, encoderValueTwo );

  //Count the speed at which the loop gets called.
  loopIterationCount++;

  //Once per second, write some stats to serial.
  if ( millis() >= millisForLastWrite + millisBetweenWrite ) {
    millisForLastWrite = millis();

    Serial.print ( "Motor Position (1/10 shaft revs): ");
    Serial.println ( encoderReader.getLastMotorPositionStep()/48/7.483 );

  }

  if ( loopIterationCount > 1000000/4 ) {
    digitalWrite(driverPinOne, 0); //Set both to 0 to stop motor.
    analogWrite(driverPinTwo, 0);
  }

}
