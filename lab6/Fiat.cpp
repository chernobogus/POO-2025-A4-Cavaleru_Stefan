#include "Fiat.h"
#include "Weather.h"
#include <iostream>
#include <cstring>
using namespace std;

Fiat::Fiat() {
	rezervor=40;
	consum=7;
	viteza[Sunny]=100;
	viteza[Rain]=90;
	viteza[Snow]=70;
	strcpy(nume,"Fiat");
	}
float Fiat::simulaterace(unsigned int lungime, Weather vreme) {
	int distanta=rezervor/consum*100;
	if(distanta<lungime) return -1;
	return 1.0*lungime/viteza[vreme]*60;
	}
char* Fiat::getname() {
	return nume;
	}