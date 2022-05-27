#include <bits/stdc++.h>
#include "tools.h"

using namespace std;

int LomutoPartition(int a[], int left, int right)
{
    int i = left - 1, j = left, key = a[right];
    while (j < right)
    {
        if (a[j] <= key)
        {
            i++;
            swapper(a[i], a[j]);
        }
        j++;
    }
    i++;
    swapper(a[i], a[right]);
    return i;
}

int HoarePartition(int a[], int low, int high)
{
    int pivot = a[low], i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swapper(a[i], a[j]);
    }
}

void qs(int a[], int left, int right)
{
    if (right > left)
    {
        int pi = HoarePartition(a, left, right);
        qs(a, left, pi);
        qs(a, pi + 1, right);
    }
}

int main()
{
    int a[2] = {3, 2};
    cout << HoarePartition(a, 0, 1) << '\n';
    display(a, 2);
}