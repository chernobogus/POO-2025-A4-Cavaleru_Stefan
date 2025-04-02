#pragma once
#include "Car.h"

class BMW : public Car {
	public:
	BMW();
int getviteza(Weather vreme)override;
	int getconsum()override;
	int getrezervor()override;	char* getname();

};