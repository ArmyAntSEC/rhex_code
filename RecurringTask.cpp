/*
 * RecurringTask.cpp
 *
 *  Created on: 12 juli 2020
 *      Author: Daniel
 */

#include "RecurringTask.h"

namespace TaskScheduler {

RecurringTask::RecurringTask(unsigned int _rate)
: runTime(0), rate(_rate)
{
}

//Sets the runTime to now so that the task starts running.
void RecurringTask::init(unsigned long int now) {
	this->runTime = now;
}

//If runTime != 0, check if we should run.
bool RecurringTask::canRun(unsigned long int now) {
	return this->runTime != 0 && now > this->runTime;
}

//Increment our timer by one iteration
void TaskScheduler::RecurringTask::run(unsigned long int /*now*/) {
	this->runTime += this->rate;
}


} /* namespace TaskScheduler */

