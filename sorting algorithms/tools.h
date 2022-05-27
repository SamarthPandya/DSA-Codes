#include <time.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void swapper(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void display(int a[], int n)
{
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        printf("%3d ", a[i]);
    }
    cout << '\n';
}

int largest(int a[], int from, int to)
{
    int out = from;
    for (int k = from + 1; k <= to; k++)
    {
        if (a[k] > a[out])
        {
            out = k;
        }
    }
    return out;
}

int *rand_array(int from, int to, int size)
{
    srand(time(0));
    int *out = new int[size];
    for (int i = 0; i < size; i++)
    {
        out[i] = from + (rand() % (to - from + 1));
    }
    return out;
}