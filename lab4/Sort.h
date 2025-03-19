#pragma once

#include <initializer_list>
#include <vector>
using namespace std;

class Sort
{
    int lista[100] = {};

public:
    int nrElem;

    Sort(int n, int minim, int maxim);
    Sort(int lista[]);
    Sort(int v[100], int n);
    Sort(int n, ...);
    Sort(const char s[100]);
    Sort(initializer_list<int> initList);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};