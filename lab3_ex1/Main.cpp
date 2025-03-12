#include <iostream>
#include "Math.h"

using namespace std;

int main() {

	Math calc;

	cout << "5+6= " << calc.Add(5, 6) << endl;
	cout << "5+6+10= " << calc.Add(5, 6, 10) << endl;
	cout << "5.2+6.3= " << calc.Add(5.2, 6.3) << endl;
	cout << "5.2+6.3+9.1= " << calc.Add(5.2, 6.3, 9.1) << endl;

	cout << "5*3= " << calc.Mul(5, 3) << endl;
	cout << "5*3*2= " << calc.Mul(5, 3, 2) << endl;
	cout << "5.5*0.5= " << calc.Mul(5.5, 0.5) << endl;
	cout << "5.5*0.5*2.0= " << calc.Mul(5.5, 0.5, 2.0) << endl;

	cout << "Add variable args: count=4, 1, 2, 3, 4: " << calc.Add(5, 1, 2, 3, 4) << endl;
	cout << "'10'+'10'=  " << calc.Add("20", "190");

	return 0;
}