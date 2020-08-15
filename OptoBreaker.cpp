/*
 * OptoBreaker.cpp
 *
 *  Created on: 15 aug. 2020
 *      Author: Daniel
 */

#include "OptoBreaker.h"
#include <Arduino.h>
OptoBreaker::OptoBreaker(int _pin):
pin(_pin)
{}

bool OptoBreaker::read() {
	int value = analogRead(pin);
	return value>128;
}
