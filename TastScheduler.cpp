/*
 * TaskScheduler.cpp
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#include "TastScheduler.h"

#include "Arduino.h"

TastScheduler::TastScheduler() :
  numTasks(0)
{
	memset( &tasks, 0, sizeof(Task)*10);
}

void TastScheduler::schedule(Task* task) {
	if ( numTasks < 10 ) {
		tasks[numTasks] = task;
		numTasks++;
	} else {
		Serial.println ( "TaskScheduler: More than 10 tasks cannot be allocated.");
	}
}

void TastScheduler::run() {
	//Serial.println ( "Running task scheduler" );
	unsigned long int now = millis();
	Task **tpp = tasks;
	for (int t = 0; t < numTasks; t++) {
		Task *tp = *tpp;
		if (tp->canRun(now)) {
			tp->run(now);
			break;
		}
		tpp++;
		//Serial.println ( "Done Checking task");
	}
	delay(100);
}

void TastScheduler::add() {
}
