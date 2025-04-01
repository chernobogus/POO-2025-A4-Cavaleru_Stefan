#include "Circuit.h"
#include "Weather.h"
#include <iostream>
using namespace std;

/* unsigned int lungime;
Weather vreme;
Car cars[100];
float finishtime[100];
int nr=0;   */

	Circuit::Circuit(){
	vreme=Sunny;
	}
	void Circuit::SetLength(unsigned int lung){
	this->lungime = lung;
	}
	void Circuit::SetWeather(Weather weather){
	this->vreme=weather;
	}
	void Circuit::AddCar(Car* c){
	cars[nr++]=c;
	}
	void Circuit::Race(){
		for (int i = 0;i < nr;i++) {
			finishtime[i]=cars[i]->simulaterace(lungime,vreme);
		}
	}
	void Circuit::ShowFinalRanks(){
		switch (vreme) {
		case 0: cout<< "Rain"; break;
		case 1: cout<< "Sunny"; break;
		case 2: cout<< "Snow"; break;
		}
		cout<<", lungime: "<<lungime<<" km"<<endl;
		for (int i = 0;i < nr-1;i++)
			for (int j = i;j < nr;j++)
				if(finishtime[i]>finishtime[j])swap(finishtime[i],finishtime[j]),swap(cars[i],cars[j]);
		int loc=1;
	for (int i = 0;i < nr;i++) if(finishtime[i]!=-1) cout<<"Locul "<< loc++<< " : "<<cars[i]->getname()<<" cu timpul de "<< finishtime[i]<<" minute" << endl;
	}
	void Circuit::ShowWhoDidNotFinish(){
		for (int i = 0;i < nr;i++) if(finishtime[i]==-1) cout<< cars[i]->getname()<< " nu a terminat cursa"<<endl;
	}