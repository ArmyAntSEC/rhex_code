/*
 * SerialEchoBeacon.cpp
 *
 *  Created on: 8 juli 2020
 *      Author: Daniel
 */

#include "SerialEchoBeacon.h"
#include <Arduino.h>

SerialEchoBeacon::SerialEchoBeacon(unsigned long int _rate)
: TimedTask(millis()), rate(_rate)
{}

void SerialEchoBeacon::run(unsigned long int ) {
	Serial.println("Beacon ping...");
	incRunTime(rate);
}
