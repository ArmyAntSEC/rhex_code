//Dependency: https://github.com/PaulStoffregen/Encoder/commit/4c4ec3ad970651324e0c197b179a682e9604ab08

//TODO: Write a position initiator that can get the motor to its starting position.

#include "Arduino.h"
#include <Encoder.h>
#include "MotorDriver.h"
#include "PID.h"
#include "SerialEchoBeacon.h"
#include "TaskScheduler.h"
#include "MotorScheduler.h"
#include "MotorController.h"

#define ENCODER_PIN_1 2
#define ENCODER_PIN_2 3
#define BREAKER_PIN A0

#define DRIVER_PIN_1 4
#define DRIVER_PIN_2 5
#define DRIVER_PIN_PWM 6

SerialEchoBeacon beacon(1000);

//MotorController controller( 1, ENCODER_PIN_1, ENCODER_PIN_2, DRIVER_PIN_1, DRIVER_PIN_2 );
//MotorScheduler scheduler( 100, &controller );

MotorDriver driver(DRIVER_PIN_1, DRIVER_PIN_2, DRIVER_PIN_PWM );

const int NUM_TASKS = 1;
TaskScheduler::Task *tasks[NUM_TASKS] = { &beacon }; //, &controller, &scheduler };
TaskScheduler::TaskScheduler sched(tasks, NUM_TASKS);

void setup() {
	//Initilaize the communication.
	Serial.begin(9600);
	Serial.println("\nHello World again!");
	beacon.init(millis());
	driver.init();
	driver.setMotorPWM(64);
}

void loop() {
	sched.run();
}
