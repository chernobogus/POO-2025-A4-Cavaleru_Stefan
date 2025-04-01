#include "Volvo.h"
#include "Weather.h"
#include <iostream>
#include <cstring>
using namespace std;

Volvo::Volvo() {
	rezervor=50;
	consum=10;
	viteza[Sunny]=125;
	viteza[Rain]=105;
	viteza[Snow]=85;
	strcpy(nume,"Volvo");
	}
float Volvo::simulaterace(unsigned int lungime, Weather vreme) {
	int distanta=rezervor/consum*100;
	if(distanta<lungime) return -1;
	return 1.0*lungime/viteza[vreme]*60;
	}
char* Volvo::getname() {
	return nume;
	}