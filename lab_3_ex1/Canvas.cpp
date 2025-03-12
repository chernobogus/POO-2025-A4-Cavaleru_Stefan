#include <iostream>
#include "Canvas.h"
using namespace std;	

Canvas::Canvas(int width, int height)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			a[i][j] = ' '; 
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int centruX = x + ray, centruY = y + ray;  //deoarece considera x,y coltul stg sus a patratului care are cercul
	for (int i = x;i <= x + 2 * ray;i++)    // 2*ray deoarece diagonala e 2r
		for (int j = y;j <= y + 2 * ray;j++)
			if (abs((i - centruX) * (i - centruX) + (j - centruY) * (j - centruY) - ray * ray) <= ray/2) 
				a[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int centruX = x + ray, centruY = y + ray;
	for (int i = x;i <= x + 2 * ray;i++)
		for (int j = y;j <= y + 2 * ray;j++)
			if ((i - centruX) * (i - centruX) + (j - centruY) * (j - centruY) <= ray * ray)
				a[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++) {
		a[i][left] = ch;
		a[i][right] = ch;
	}
	for (int i = left;i <= right;i++) {
		a[top][i] = ch;
		a[bottom][i] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++)
		for (int j = left;j <= right;j++)
			a[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	a[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int m = 2 * (y2 - y1); 
    int slope_err = m - (x2 - x1); 
    for (int x = x1, y = y1; x <= x2; x++) { 
        a[y][x]=ch;  //daca punem a[x][y] da linia rotita cu -90 deg
        slope_err += m;  
        if (slope_err >= 0) { 
            y++; 
            slope_err -= 2 * (x2 - x1); 
        } 
    } //bresenham
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
			cout << a[i][j]<<' ';
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			a[i][j] = ' ';
}