/*
 * RecurringTask.h
 *
 *  Created on: 12 juli 2020
 *      Author: Daniel
 */

#ifndef RECURRINGTASK_H_
#define RECURRINGTASK_H_

#include "Task.h"

namespace TaskScheduler {

class RecurringTask: public Task { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	RecurringTask( unsigned int _rate );
    virtual bool canRun(unsigned long int now);
    inline void setRate(unsigned long int _rate) { runTime += _rate; }
    virtual void run(unsigned long int now);
    void init( unsigned long int now );
    inline void start() { this->isRunning = true; }
    inline void stop() { this->isRunning = false; }
private:
    unsigned long int runTime;
    unsigned int rate;
    bool isRunning;
};

} /* namespace TaskScheduler */

#endif /* RECURRINGTASK_H_ */
