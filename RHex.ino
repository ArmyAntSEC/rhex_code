//Dependency: https://github.com/PaulStoffregen/Encoder/commit/4c4ec3ad970651324e0c197b179a682e9604ab08

#include "Arduino.h"
#include <Encoder.h>
#include "MotorDriver.h"
#include "PID.h"
#include "SerialEchoBeacon.h"
#include "TaskScheduler.h"
#include "MotorScheduler.h"
#include "MotorController.h"
#include "OptoBreaker.h"
#include "MotorPositionInitiator.h"
#include "MotorStateHandler.h"

#define ENCODER_PIN_1 2
#define ENCODER_PIN_2 3
#define BREAKER_PIN A0

#define DRIVER_PIN_1 4
#define DRIVER_PIN_2 5
#define DRIVER_PIN_PWM 6

SerialEchoBeacon beacon(5000);

OptoBreaker breaker( BREAKER_PIN );
//Encoder encoder( ENCODER_PIN_1, ENCODER_PIN_2 );
MotorStateHandler stateHandler ( 50 );

MotorDriver driver(DRIVER_PIN_1, DRIVER_PIN_2, DRIVER_PIN_PWM );

MotorPositionInitiator initiator(  &stateHandler, &driver, &breaker );

TaskScheduler sched = TaskScheduler();

void setup() {
	//Initilaize the communication.
	Serial.begin(9600);
	Serial.println("\nHello World again!");

	stateHandler.setInitiator(&initiator);
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
