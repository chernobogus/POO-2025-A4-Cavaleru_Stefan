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
int Volvo::getviteza(Weather vreme) {return viteza[vreme]; }
	int Volvo::getconsum(){return consum;}
	int Volvo::getrezervor() {return rezervor;}
char* Volvo::getname() {
	return nume;
	}