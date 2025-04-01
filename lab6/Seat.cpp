#include "Seat.h"
#include "Weather.h"
#include <iostream>
#include <cstring>
using namespace std;

Seat::Seat() {
	rezervor=35;
	consum=4;
	viteza[Sunny]=90;
	viteza[Rain]=70;
	viteza[Snow]=60;
	strcpy(nume,"Seat");
	}
float Seat::simulaterace(unsigned int lungime, Weather vreme) {
	int distanta=rezervor/consum*100;
	if(distanta<lungime) return -1;
	return 1.0*lungime/viteza[vreme]*60;
	}
char* Seat::getname() {
	return nume;
	}