/*
 * FIRFilter.h
 *
 *  Created on: 28 nov. 2019
 *      Author: Daniel
 */

#ifndef FIRFILTER_H_
#define FIRFILTER_H_

#include <FixedPointsCommon.h>

class FIRFilter {
private:
	SQ15x16 filterConstant = 0;
	SQ15x16 lastValue = 0;

public:
	FIRFilter( SQ15x16 filterConstant );
	SQ15x16 step( SQ15x16 newValue );
};

#endif /* FIRFILTER_H_ */
