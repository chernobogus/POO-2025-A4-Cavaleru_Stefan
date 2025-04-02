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
int Fiat::getviteza(Weather vreme) {return viteza[vreme]; }
	int Fiat::getconsum(){return consum;}
	int Fiat::getrezervor() {return rezervor;}
char* Fiat::getname() {
	return nume;
	}