#pragma once
#include "Weather.h"

class Car {
public:
	int rezervor, consum, viteza[3];
	char nume[50];

	virtual float simulaterace(unsigned int lungime,Weather vreme)=0;
	virtual char* getname()=0;

};