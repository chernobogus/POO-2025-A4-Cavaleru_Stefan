#pragma once
#include "Car.h"

class Volvo : public Car {
	public:
	Volvo();
int getviteza(Weather vreme)override;
	int getconsum()override;
	int getrezervor()override;	char* getname();

};