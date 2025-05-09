#pragma once

class Canvas
{
    int width=50, height=50;
    char a[50][50] = {};

public:
    Canvas(int width,int height);
    Canvas() = default; // eroare no appropriate default constructor available fara

    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};
#pragma once
