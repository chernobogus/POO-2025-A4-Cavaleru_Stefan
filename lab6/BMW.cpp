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
int BMW::getviteza(Weather vreme) {return viteza[vreme]; }
	int BMW::getconsum(){return consum;}
	int BMW::getrezervor() {return rezervor;}
char* BMW::getname() {
	return nume;
	}