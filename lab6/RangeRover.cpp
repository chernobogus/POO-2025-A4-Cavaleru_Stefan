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
int RangeRover::getviteza(Weather vreme) {return viteza[vreme]; }
	int RangeRover::getconsum(){return consum;}
	int RangeRover::getrezervor() {return rezervor;}
char* RangeRover::getname() {
	return nume;
	}