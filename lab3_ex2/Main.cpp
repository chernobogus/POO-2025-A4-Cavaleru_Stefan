#include <iostream>
#include "Canvas.h"
using namespace std;

int main() {

	Canvas canvas(50, 50);

	canvas.DrawCircle(10, 10, 10, 'g');
	canvas.FillCircle(14, 14, 4, 'h');
	canvas.DrawRect(40, 40, 45, 45, 'k');
	canvas.FillRect(35, 2, 48, 15, 'z');
	canvas.DrawLine(1, 1, 30, 5, 'o');
	canvas.Print();
	canvas.Clear();
	return 0;
}