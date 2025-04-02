#pragma once
#include "Weather.h"

class Car {
protected:
	int rezervor, consum, viteza[3];
	char nume[50];
public:
	virtual int getviteza(Weather vreme)=0;
	virtual int getconsum()=0;
	virtual int getrezervor()=0;
	virtual char* getname()=0;

};