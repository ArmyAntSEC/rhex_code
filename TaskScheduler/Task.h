/*
 * Task.h
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#ifndef TASK_H_
#define TASK_H_

namespace TaskScheduler {

class Task { // @suppress("Class has a virtual method and non-virtual destructor")
public:
    virtual bool canRun(unsigned long int now) = 0;
    virtual void run(unsigned long int now) = 0;
};

} /* namespace TaskScheduler */

#endif /* TASK_H_ */
