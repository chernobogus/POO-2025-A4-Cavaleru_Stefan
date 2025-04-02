#pragma once
#include "Car.h"

class RangeRover : public Car {
	public:
	RangeRover();
int getviteza(Weather vreme)override;
	int getconsum()override;
	int getrezervor()override;	char* getname();

};