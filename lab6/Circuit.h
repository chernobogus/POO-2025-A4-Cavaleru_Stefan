#pragma once
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Weather.h"
#include "Car.h"

class Circuit {
public:
unsigned int lungime;
Weather vreme;
Car* cars[100] = {};
float finishtime[100] = {};
int nr=0;

//public:
	Circuit();
	void SetLength(unsigned int lung);
	void SetWeather(Weather weather);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};