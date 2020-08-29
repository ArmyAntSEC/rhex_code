//Dependency: https://github.com/PaulStoffregen/Encoder/commit/4c4ec3ad970651324e0c197b179a682e9604ab08

#include "Arduino.h"
#include <Encoder.h>
#include "MotorDriver.h"
#include "PID.h"
#include "SerialEchoBeacon.h"
#include "TaskScheduler.h"
#include "OptoBreaker.h"
#include "MotorPositionInitiator.h"
#include "MotorStateHandler.h"
#include "MotorSinWaver.h"
#include "MotorPIDRegulator.h"
#include "PID.h"

#define ENCODER_PIN_1 2
#define ENCODER_PIN_2 3
#define BREAKER_PIN A0

#define DRIVER_PIN_1 4
#define DRIVER_PIN_2 5
#define DRIVER_PIN_PWM 6

SerialEchoBeacon beacon(5000);

OptoBreaker breaker( BREAKER_PIN );
Encoder encoder( ENCODER_PIN_1, ENCODER_PIN_2 );
double Kp = 100;
double Ki = 0;
double Kd = 10;
int sampleTime = 50;

PID pid(Kp, Ki, Kd, sampleTime, P_ON_E, DIRECT );

MotorStateHandler stateHandler ( sampleTime );


MotorDriver driver(DRIVER_PIN_1, DRIVER_PIN_2, DRIVER_PIN_PWM );

MotorPositionInitiator initiator(  &stateHandler, &driver, &breaker );
MotorSinWaver waver(  &stateHandler, &driver );
MotorPIDRegulator regulator( &stateHandler, &driver, &encoder, &pid );

TaskScheduler sched = TaskScheduler();

void setup() {
	//Initilaize the communication.
	Serial.begin(9600);
	Serial.println("\nHello World again!");

	stateHandler.setInitiator(&initiator);
	stateHandler.setMainLoop(&waver);
	stateHandler.startInitiator();
	stateHandler.init(millis());

	//Add the objects to the scheduler
	sched.add( &beacon );
	sched.add( &stateHandler );

	beacon.init(millis());
	driver.init();
}

void loop() {
	sched.run();

}

/*
 * double MotorScheduler::interp1(int xlen, double x[], double y[], double xq) {
	//Note: X must be strictly monotonically increasing.<

	//Check that we are in range
	if ( xq < x[0] || xq > x[xlen-1] ) {
		return 1.0/0.0;
	}

	//Now find what segment we are in
	int segment = 0;
	while ( xq > x[segment+1] ) { segment++; }

	//Compute the start ane endpoints of the current segment.
	double x0 = x[segment];
	double x1 = x[segment+1];
	double y0 = y[segment];
	double y1 = y[segment+1];

	//Compute the relative position within the segment in x
	double xt = (xq - x0)/(x1-x0);

	//Compute the Y postion to return
	double yRet = y0 + (y1-y0)*xt;

	return yRet;
}
 */
