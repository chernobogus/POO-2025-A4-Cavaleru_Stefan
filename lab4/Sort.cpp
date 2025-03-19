#include <iostream>
#include <cstdlib>
#include <stdarg.h>
#include <cstring>
#include <vector>
#include <initializer_list>
#include "Sort.h"

using namespace std;


void descend(int lista[],int nr) {  //in cazul in care ascendent e false
    for(int i=0;i<nr/2;i++)
        swap(lista[i],lista[nr-i-1]);
}

//constructori


Sort::Sort(initializer_list<int> initList) {  
    int i = 0;
    for (int temp : initList)
        lista[i++]=temp;
    nrElem = i; }


Sort::Sort(int n, int minim, int maxim)
{
    nrElem=n;
    int range = maxim - minim;
    for (int i = 0; i < n; i++){
        lista[i] = rand() % range + minim;
    }
}

Sort::Sort(int lista[]) //Initialization list ?
{
    ///nrElem = l;
}

Sort::Sort(int v[100], int n)
{
    nrElem=n;
    for (int i = 0; i < n; i++)
    {
        lista[i] = v[i];
    }
}

Sort::Sort(int n, ...)
{
    nrElem=n;
    va_list args;
    va_start(args, n);
    int i = 0;

    while (n != 0)
    {
        lista[i] = va_arg(args, int);
        i++;
        n--;
    }
    va_end(args);
}

Sort::Sort(const char s[100])
{
    nrElem = 0;
    int i = 0;
    int nrCurent = 0;

    while (i < strlen(s))
    {
        if (s[i] != ',') nrCurent = nrCurent * 10 + s[i] - '0';
        else{
            lista[nrElem] = nrCurent;
            nrElem++;
            nrCurent = 0;
        }
        i++;
    }
    lista[nrElem] = nrCurent;
    nrElem++;
}


//functii


void Sort::InsertSort(bool ascendent)
{
    int a;
    for (int i = 1; i < nrElem; i++)
    {
        a = lista[i];
        int j = i - 1;

        while (j >= 0 && lista[j] > a)
        {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = a;
    }
    if(!ascendent)descend(lista,nrElem);
}

int partition(int lista[], int low, int high) {
    int pivot = lista[high]; // ultimul elem ca pivot
    int i = low - 1; // elem mai mici decat pivot

    for (int j = low; j < high; j++) {
        if (lista[j] < pivot) {
            i++;
            swap(lista[i], lista[j]); // mutam elementul mai mic in stg
        }
    }
    swap(lista[i + 1], lista[high]); // mutam pivotul
    return i + 1;
}

void qs_rec(int lista[], int low, int high) {
    if (low < high) {
        int pi = partition(lista, low, high); // obtinem pivotul

        qs_rec(lista, low, pi - 1); // sort stg
        qs_rec(lista, pi + 1, high); // sort drpt
    }
}

void Sort::QuickSort(bool ascendent)
{
    qs_rec(lista,0,nrElem-1);
    if(!ascendent)descend(lista,nrElem);
}

void Sort::BubbleSort(bool ascendent )
{
    for (int i = 0; i < nrElem - 1; i++)
        for (int j = 0; j < nrElem - i - 1; j++)
            if (lista[j] > lista[j + 1]) swap(lista[j],lista[j+1]);
    if(!ascendent)descend(lista,nrElem);
}

void Sort::Print()
{
    for (int i = 0; i < nrElem; i++)
        cout << lista[i] << " ";
}

int Sort::GetElementsCount()
{
    return nrElem;
}

int Sort::GetElementFromIndex(int index)
{
	return lista[index];
}