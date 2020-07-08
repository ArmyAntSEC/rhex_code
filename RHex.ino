//Dependency: https://github.com/PaulStoffregen/Encoder/commit/4c4ec3ad970651324e0c197b179a682e9604ab08
//DEpendency: https://github.com/br3ttb/Arduino-PID-Library/commit/9b4ca0e5b6d7bab9c6ac023e249d6af2446d99bb

#include "Arduino.h"
#include <Encoder.h>
#include <PID_v1.h>

#include "MotorDriver.h"
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
