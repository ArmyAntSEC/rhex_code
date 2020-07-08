/*
 * TimedTask.h
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#ifndef TIMEDTASK_H_
#define TIMEDTASK_H_

#include "Task.h"

namespace TaskScheduler {

class TimedTask: public Task { // @suppress("Class has a virtual method and non-virtual destructor")
public:
    inline TimedTask(unsigned long int when) { runTime = when; }
    virtual bool canRun(unsigned long int now);
    inline void setRunTime(unsigned long int when) { runTime = when; }
    inline void incRunTime(unsigned long int inc) { runTime += inc; }
    inline unsigned long int getRunTime() { return runTime; }
protected:
    unsigned long int runTime;
};

} /* namespace TaskScheduler */

#endif /* TIMEDTASK_H_ */
