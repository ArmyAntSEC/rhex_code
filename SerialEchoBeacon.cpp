/*
 * SerialEchoBeacon.cpp
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#include "SerialEchoBeacon.h"
#include <Arduino.h>

SerialEchoBeacon::SerialEchoBeacon(unsigned long int _rate)
: RecurringTask(_rate)
{}

void SerialEchoBeacon::run(unsigned long int now) {
	RecurringTask::run(now);
	Serial.println("Beacon ping...");

}
