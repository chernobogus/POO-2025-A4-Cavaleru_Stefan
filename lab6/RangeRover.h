#pragma once
#include "Car.h"

class RangeRover : public Car {
	public:
	RangeRover();
	float simulaterace(unsigned int lungime, Weather vreme);
	char* getname();

};