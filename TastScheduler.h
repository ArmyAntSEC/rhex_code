/*
 * TaskScheduler.h
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#ifndef TASTSCHEDULER_H_
#define TASTSCHEDULER_H_

#include "Task.h"

class TastScheduler {
public:
    TastScheduler();
    void schedule ( Task* task );
    void add();
    void run();
private:
    Task *tasks[10];
    int numTasks;
};

#endif /* TASTSCHEDULER_H_ */
