#include <bits/stdc++.h>
#include "tools.h"

using namespace std;

void heapify_util(int a[], int node, int to)
{
    int largest = node;
    int left = 2 * node + 1;
    int right = left + 1;
    if (left <= to && a[left] > a[largest])
    {
        largest = left;
    }
    if (right <= to && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != node)
    {
        swapper(a[largest], a[node]);
        heapify_util(a, largest, to);
    }
}

void heapify(int a[], int from, int to)
{
    int right = (to - from + 1) / 2;
    int left = (to - from + 1) / 4;
    while (right > 0)
    {
        for (int i = left; i < right; i++)
        {
            heapify_util(a, i, to);
        }
        right = left;
        left = left / 2;
    }
}

void heap_sort(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        heapify(a, 0, i);
        swapper(a[0], a[i]);
    }
}

int main()
{
    int a[6] = {4, 3, 1, 2, 0, 1};
    heap_sort(a, 6);
    display(a, 6);
}