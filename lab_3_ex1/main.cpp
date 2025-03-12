#include <iostream>
#include "Math.h"
#include "Canvas.h"
using namespace std;

int main() {

	
cout<<endl<<endl<<"---------------------------------------- Problema 1 ----------------------------------------"<<endl<<endl;

	Math calc;

	cout<<"5+6= "<< calc.Add(5, 6) << endl;
	cout<<"5+6+10= "<< calc.Add(5,6,10)<<endl;
	cout<<"5.2+6.3= "<< calc.Add(5.2,6.3)<<endl;
	cout<<"5.2+6.3+9.1= "<< calc.Add(5.2,6.3,9.1)<<endl;

	cout<<"5*3= "<< calc.Mul(5,3)<<endl;
	cout<<"5*3*2= "<< calc.Mul(5,3,2)<<endl;
	cout<<"5.5*0.5= "<< calc.Mul(5.5,0.5)<<endl;
	cout<<"5.5*0.5*2.0= "<< calc.Mul(5.5,0.5,2.0)<<endl;

	cout<<"Add variable args: count=4, 1, 2, 3, 4: "<<calc.Add(5, 1, 2, 3, 4)<<endl;
	cout<<"'10'+'10'=  "<<calc.Add("20", "190");

	
cout<<endl<<endl<<"---------------------------------------- Problema 2 ----------------------------------------"<<endl<<endl;

	Canvas canvas(50,50);

	canvas.DrawCircle(10,10,10,'g');
	canvas.FillCircle(14,14,4,'h');
	canvas.DrawRect(40,40,45,45,'k');
	canvas.FillRect(35,2,48,15,'z');
	canvas.DrawLine(1,1,30,5,'o');
	canvas.Print();



	return 0;
}