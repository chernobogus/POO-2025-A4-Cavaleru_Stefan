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
int Seat::getviteza(Weather vreme) {return viteza[vreme]; }
	int Seat::getconsum(){return consum;}
	int Seat::getrezervor() {return rezervor;}
char* Seat::getname() {
	return nume;
	}