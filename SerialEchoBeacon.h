/*
 * SerialEchoBeacon.h
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#ifndef SERIALECHOBEACON_H_
#define SERIALECHOBEACON_H_

#include "TimedTask.h"

class SerialEchoBeacon: public TaskScheduler::TimedTask { // @suppress("Class has a virtual method and non-virtual destructor")

public:
    // Create a new blinker for the specified pin and rate.
	SerialEchoBeacon(unsigned long int _rate);
    virtual void run(unsigned long int now);
private:
	unsigned long int rate;
};

#endif /* SERIALECHOBEACON_H_ */
