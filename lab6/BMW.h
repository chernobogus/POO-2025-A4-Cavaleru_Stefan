#pragma once
#include "Car.h"

class BMW : public Car {
	public:
	BMW();
	float simulaterace(unsigned int lungime, Weather vreme);
	char* getname();

};