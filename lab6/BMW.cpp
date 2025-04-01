#include "BMW.h"
#include "Weather.h"
#include <iostream>
#include <cstring>
using namespace std;

BMW::BMW() {
	rezervor=50;
	consum=8;
	viteza[Sunny]=140;
	viteza[Rain]=110;
	viteza[Snow]=90;
	strcpy(nume,"BMW");
	}
float BMW::simulaterace(unsigned int lungime, Weather vreme) {
	int distanta=rezervor/consum*100;
	if(distanta<lungime) return -1;
	return (1.0)*lungime/viteza[vreme]*60;
	}
char* BMW::getname() {
	return nume;
	}