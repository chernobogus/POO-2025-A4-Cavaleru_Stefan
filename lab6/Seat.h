#pragma once
#include "Car.h"

class Seat : public Car {
	public:
	Seat();
	int getviteza(Weather vreme)override;
	int getconsum()override;
	int getrezervor()override;
	char* getname();

};