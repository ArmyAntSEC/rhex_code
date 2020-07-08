/*
 * TaskScheduler.cpp
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#include "TaskScheduler.h"

#include "Arduino.h"

namespace TaskScheduler {

TaskScheduler::TaskScheduler(Task **_tasks, unsigned int _numTasks) :
  tasks(_tasks),
  numTasks(_numTasks)
{}

void TaskScheduler::run() {
	unsigned long int now = millis();
	Task **tpp = tasks;
	for (int t = 0; t < numTasks; t++) {
		Task *tp = *tpp;
		if (tp->canRun(now)) {
			tp->run(now);
			break;
		}
		tpp++;
	}
}

} /* namespace TaskScheduler */
