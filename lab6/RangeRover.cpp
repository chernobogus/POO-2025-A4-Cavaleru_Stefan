#include "RangeRover.h"
#include "Weather.h"
#include <iostream>
#include <cstring>
using namespace std;

RangeRover::RangeRover() {
	rezervor=50;
	consum=10;
	viteza[Sunny]=120;
	viteza[Rain]=100;
	viteza[Snow]=80;
	strcpy(nume,"RangeRover");
	}
float RangeRover::simulaterace(unsigned int lungime, Weather vreme) {
	int distanta=rezervor/consum*100;
	if(distanta<lungime) return -1;
	return 1.0*lungime/viteza[vreme]*60;
	}
char* RangeRover::getname() {
	return nume;
	}