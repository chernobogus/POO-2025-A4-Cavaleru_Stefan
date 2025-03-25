#pragma once


class Number
{
   int Base, numlen;
   char number[100] = {};


public:
   Number(const char * value, int base); // where base is between 2 and 16
   ~Number();

   // add operators and copy/move constructor

   bool operator < (Number& num); 
   bool operator > (Number& num);
   bool operator <= (Number& num);
   bool operator >= (Number& num); 
   bool operator == (Number& num);
   friend Number operator+ ( Number& num1, Number& num2);
   friend Number operator- ( Number& num1, Number& num2);
   Number& operator--();
   Number operator--(int);

   int GetBase10Value(); 

   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base
};
