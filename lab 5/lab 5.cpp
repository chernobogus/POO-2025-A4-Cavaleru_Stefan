#include <iostream>
#include "Number.h"

using namespace std;

int main()
{   
    Number numar1("10001", 2);
numar1.Print();
numar1.SwitchBase(16);
cout << endl;
numar1.Print();
cout << endl;

Number numar2("162", 10);
numar2.Print();
numar2.SwitchBase(12);
cout << endl;
numar2.Print();
cout << endl;

Number numar3("16", 7);
numar3.Print();
numar3.SwitchBase(5);
cout << endl;
numar3.Print();
cout << endl;

Number numar4("100", 2);
Number numar5("10", 2);

Number diferenta = numar4 - numar5;
diferenta.Print(); cout<<endl;

Number suma = numar5 + numar4;
suma.Print(); cout<<endl;

numar2--;
numar2.Print(); cout<<endl;

--numar2;
numar2.Print(); cout<<endl;

if (numar4 > numar5) 
    cout << numar4.GetBase10Value() << " este mai mare decat " << numar5.GetBase10Value() << endl;
else 
    cout << numar5.GetBase10Value() << " este mai mare decat " << numar4.GetBase10Value() << endl;

    
    return 0;
}