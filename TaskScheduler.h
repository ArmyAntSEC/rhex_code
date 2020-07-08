/*
 * TaskScheduler.h
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#ifndef TASKSCHEDULER_H_
#define TASKSCHEDULER_H_

#include "Task.h"

namespace TaskScheduler {

class TaskScheduler {
public:
    TaskScheduler(Task **task, unsigned int numTasks);
    void run();
private:
    Task **tasks;
    int numTasks;
};

} /* namespace TaskScheduler */

#endif /* TASKSCHEDULER_H_ */
