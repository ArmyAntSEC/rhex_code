/*
 * FIRFilter.cpp
 *
 *  Created on: 28 nov. 2019
 *      Author: Daniel
 */

#include "FIRFilter.h"

FIRFilter::FIRFilter( SQ15x16 filterConstant )
{
	this->filterConstant = filterConstant;
}

SQ15x16 FIRFilter::step( SQ15x16 newValue )
{
	this->lastValue = newValue*this->filterConstant + this->lastValue*(1-this->filterConstant);
	return this->lastValue;
}
