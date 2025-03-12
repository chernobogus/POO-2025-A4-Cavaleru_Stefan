#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

     int Math::Add(int x, int y) { return x+y; }
     int Math::Add(int x, int y, int z) { return x+y+z; }
     int Math::Add(double x, double y) { return x+y; }
     int Math::Add(double x, double y, double z) {return x+y+z;}
     int Math::Mul(int x, int y) { return x*y;}
     int Math::Mul(int x, int y, int z) {return x*y*z;}
     int Math::Mul(double x, double y) {return x*y;}
     int Math::Mul(double x, double y, double z) {return x*y*z;}
     int Math::Add(int count, ...) { 
         int sum=0;
         va_list args;                      //declara lista
        va_start(args, count);              //initializeaza lista
        for (int i = 0; i < count; i++) 
        sum+=va_arg(args, int);             //aduna urmatorul elem de tip int din args
        va_end(args);                       //dealoca memoria
         return sum;} // sums up a list of integers

     char* Math::Add(const char* x, const char* y) {
      /*  char* s = new char[strlen(x) + strlen(y) + 1];
        strcpy (s, x);
        strcat (s, y);
        return s; */
    
     int i,j,carry=0,maxi = max(strlen(x),strlen(y)) + 2;
     char* s = new char[maxi]; maxi--;
     s[maxi--] = '\0';
     int dx,dy;
     for (i = strlen(x) - 1, j = strlen(y) - 1;i >= 0, j >= 0;i--, j--) {
         if(i>=0)dx=x[i]-'0'; else dx=0;
         if(j>=0)dy=y[j]-'0'; else dy=0;
         s[maxi--] = (dx+dy + carry) % 10+'0'; carry = (dx + dy + carry) / 10;
     }
         return s+1;
    }

