//Dependency: https://github.com/PaulStoffregen/Encoder/commit/4c4ec3ad970651324e0c197b179a682e9604ab08

#include "Arduino.h"
#include <Encoder.h>
#include "MotorDriver.h"
#include "PID.h"
#include "SerialEchoBeacon.h"
#include "TaskScheduler.h"
#include "MotorScheduler.h"
#include "MotorController.h"

#define ENCODER_PIN_1 0
#define ENCODER_PIN_2 0
#define DRIVER_PIN_1 0
#define DRIVER_PIN_2 0

SerialEchoBeacon beacon(1000);
MotorController controller( 1, ENCODER_PIN_1, ENCODER_PIN_2, DRIVER_PIN_1, DRIVER_PIN_2 );
MotorScheduler scheduler( 100, &controller );

const int NUM_TASKS = 3;
TaskScheduler::Task *tasks[NUM_TASKS] = { &beacon, &controller, &scheduler };
TaskScheduler::TaskScheduler sched(tasks, NUM_TASKS);

void setup() {
	//Initilaize the communication.
	Serial.begin(9600);
	Serial.println("Hello World again!");
}

void loop() {
	sched.run();
}
