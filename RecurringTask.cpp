/*
 * RecurringTask.cpp
 *
 *  Created on: 12 juli 2020
 *      Author: Daniel
 */

#include "RecurringTask.h"
#include <Arduino.h>

RecurringTask::RecurringTask(unsigned int _rate)
: runTime(0), rate(_rate), isRunning(false)
{
}

//Sets the runTime to now so that the task starts running.
void RecurringTask::init( unsigned long int now = 0 ) {
	this->runTime = now;
	this->start();
}

//If runTime != 0, check if we should run.
bool RecurringTask::canRun(unsigned long int now) {
	return this->isRunning && now > this->runTime;
}

//Increment our timer by one iteration
void RecurringTask::run(unsigned long int /*now*/) {
	this->runTime += this->rate;
}

