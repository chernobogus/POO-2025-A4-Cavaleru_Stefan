#pragma once
#include "Car.h"

class Seat : public Car {
	public:
	Seat();
	float simulaterace(unsigned int lungime, Weather vreme);
	char* getname();

};