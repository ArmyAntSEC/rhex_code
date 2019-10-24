/*
 * MotorDriver.h
 *
 *  Created on: 24 okt. 2019
 *      Author: Daniel
 */

#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_

class MotorDriver {
private:
	int driverPinOne;
	int driverPinTwo;

public:
	MotorDriver ( int driverPinOne, int driverPinTwo );
	void setMotorPWM( int motorPWM );
};

#endif /* MOTORDRIVER_H_ */
