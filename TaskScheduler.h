/*
 * TaskScheduler.h
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#ifndef TASKSCHEDULER_H_
#define TASKSCHEDULER_H_

#include "Task.h"

class TaskScheduler {
public:
    TaskScheduler();
    void schedule ( Task* task );
    void run();
private:
    Task *tasks[10];
    int numTasks;
};

#endif /* TASKSCHEDULER_H_ */
