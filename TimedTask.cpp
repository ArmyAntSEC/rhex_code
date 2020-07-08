/*
 * TimedTask.cpp
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#include "TimedTask.h"

namespace TaskScheduler {

bool TimedTask::canRun(unsigned long int now) {
    return now >= runTime;
}

} /* namespace TaskScheduler */
