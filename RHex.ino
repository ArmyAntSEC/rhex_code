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

//MotorController controller( 1, ENCODER_PIN_1, ENCODER_PIN_2, DRIVER_PIN_1, DRIVER_PIN_2 );
//MotorScheduler scheduler( 100, &controller );

MotorDriver driver(DRIVER_PIN_1, DRIVER_PIN_2, DRIVER_PIN_PWM );
OptoBreaker breaker( BREAKER_PIN );
MotorPositionInitiator initiator( 100, &driver, &breaker );

//TODO: Have the state handler be the RecurringTask and let the initiator and other state just be implementation objects.
MotorStateHandler stateHandler ( 100, &initiator );

TaskScheduler sched = TaskScheduler();

//TODO: Why does this not work?
//sched.schedule( &beacon );
//sched.schedule( &initiator );

void setup() {
	//Initilaize the communication.
	Serial.begin(9600);
	Serial.println("\nHello World again!");
	beacon.init(millis());
	driver.init();
	initiator.init(millis());
}

void loop() {
	sched.run();
}
