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
	int driverPinPWM;

public:
	MotorDriver ( int _driverPinOne, int _driverPinTwo, int _driverPinPWM );
	void init();
	void setMotorPWM( int motorPWM );
};

#endif /* MOTORDRIVER_H_ */
