//Dependency: https://github.com/PaulStoffregen/Encoder/commit/4c4ec3ad970651324e0c197b179a682e9604ab08

#include "Arduino.h"
#include <Encoder.h>
#include "MotorDriver.h"
#include "PID.h"
#include "SerialEchoBeacon.h"
#include "TaskScheduler.h"

SerialEchoBeacon beacon(1000);
const int NUM_TASKS = 1;
TaskScheduler::Task *tasks[NUM_TASKS] = { &beacon };
TaskScheduler::TaskScheduler sched(tasks, NUM_TASKS);

void setup() {
	//Initilaize the communication.
	Serial.begin(9600);
	Serial.println("Hello World again!");
}

void loop() {
	sched.run();
}
