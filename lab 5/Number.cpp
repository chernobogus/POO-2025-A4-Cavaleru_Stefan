#include <cstring>
#include <iostream>
#include <cmath>
#include "Number.h"

using namespace std;

Number::Number(const char* value, int base) {
	strcpy(number,value);
	Base=base;
	numlen=strlen(number);
}

void Number:: Print() {
	cout << "numarul este: " << number << " in baza " << Base;
}

int Number::GetBase10Value(){
	int rez = 0, putere = 1;
	int i;

	for (i = numlen - 1; i >= 0; i--)
	{
		if (number[i] >= '0' && number[i] <= '9') {
			rez = rez + (number[i] - '0') * putere; 
		}
		else {
			rez = rez + (number[i] - 'A' + 10) * putere; // A = 11, B = 12, C = 13, D = 14, E = 15, F = 16 
		}
		putere = putere * Base; // creste puterea bazei (2^0, 2^1, 2^2, ...)
	}
	return rez;
}

void Number::SwitchBase(int newBase) {

	int val = GetBase10Value(); 
	int rest = 0;

	char result[100];
	int i=log10(val)+2;
	result[i] = '\0'; i--;
	for(;i>=0;i--) {
        int rest = val % newBase;
        val = val / newBase;
        if (rest <= 9) result[i] = rest + '0';
        else result[i] = rest - 10  + 'A';
    }
	strcpy(number, result);
	Base = newBase;
}

int Number::GetDigitsCount() {
	return numlen;
}

int Number::GetBase() { return Base;}

Number::~Number() { 
for(int i=0;i<GetDigitsCount();i++)
number[i]=NULL;
}

//--------------------operatori--------------------

bool Number::operator < (Number& num){
	if(GetBase10Value()<num.GetBase10Value()) return 1;
	return 0;}

bool Number::operator > (Number& num){
	if(GetBase10Value()>num.GetBase10Value()) return 1;
	return 0;}

bool Number::operator <= (Number& num){
	if(GetBase10Value()<=num.GetBase10Value()) return 1;
	return 0;}

bool Number::operator >= (Number& num){
	if(GetBase10Value()>=num.GetBase10Value()) return 1;
	return 0;}

bool Number::operator == (Number& num){
	if(GetBase10Value()==num.GetBase10Value()) return 1;
	return 0;}

Number operator+ ( Number& num1,  Number& num2) {
	int maxbase=max(num1.GetBase(), num2.GetBase());
	int sum= num1.GetBase10Value() + num2.GetBase10Value();
	char result[100];
	int i=log10(sum)+2;
	result[i] = '\0'; i--;
	for(;i>=0;i--) {
        int rest = sum % maxbase;
        sum = sum / maxbase;
        if (rest <= 9) result[i] = rest + '0';
        else result[i] = rest-10 + 'A';
    }
	return Number(result, maxbase);
}

Number operator- ( Number& num1,  Number& num2) {
	int maxbase=max(num1.GetBase(), num2.GetBase());
	int dif= abs(num1.GetBase10Value() - num2.GetBase10Value());
	char result[100];
	int i=log10(dif)+2;
	result[i] = '\0'; i--;
	for(;i>=0;i--) {
        int rest = dif % maxbase;
        dif = dif / maxbase;
        if (rest <= 9) result[i] = rest + '0';
        else result[i] = rest-10 + 'A';
    }
	return Number(result, maxbase);
}

Number& Number::operator--(){
    strcpy(number, number + 1);
    numlen = strlen(number);
    return *this;
}

Number Number::operator--(int){
    number[strlen(number) - 1] = '\0';
    numlen = strlen(number); 
    return *this;
}
