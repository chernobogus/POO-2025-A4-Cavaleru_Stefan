#pragma once
#include "Car.h"

class Fiat : public Car {
public:
	Fiat();
	float simulaterace(unsigned int lungime, Weather vreme);
	char* getname();

};