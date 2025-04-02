#pragma once
#include "Car.h"

class Fiat : public Car {
public:
	Fiat();
int getviteza(Weather vreme) override;
	int getconsum() override;
	int getrezervor() override;	char* getname();

};