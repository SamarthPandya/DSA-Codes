#include <bits/stdc++.h>
#include "tools.h"
#include <math.h>

// Doesn't work

void insertion_sort(int a[], int from, int to)
{
    for (int i = from + 1; i <= to; i++)
    {
        int j = i;
        while (a[j] < a[j - 1] && j > 0)
        {
            swapper(a[j], a[j - 1]);
            j--;
        }
    }
}

int partition(int a[], int left, int right)
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

void qs(int a[], int left, int right)
{
    if (right > left)
    {
        int pi = partition(a, left, right);
        qs(a, left, pi - 1);
        qs(a, pi + 1, right);
    }
}

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

void heap_sort(int a[], int from, int to)
{
    for (int i = to; i >= from; i--)
    {
        heapify(a, from, i);
        swapper(a[from], a[i]);
    }
}

void intro_sort_util(int a[], int from, int to, int max_depth)
{
    if (to > from)
    {
        int size = to - from + 1;
        if (size < 16)
        {
            // cout << "I.S from index " << from << " to " << to << '\n';
            insertion_sort(a, from, to);
        }
        if (max_depth == 0)
        {
            // cout << "H.S from index " << from << " to " << to << '\n';
            heap_sort(a, from, to);
        }
        // cout << "Q.S from index " << from << " to " << to << '\n';
        int pi = partition(a, from, to);
        intro_sort_util(a, from, pi - 1, max_depth - 1);
        intro_sort_util(a, pi + 1, to, max_depth - 1);
    }
}

void intro_sort(int a[], int n)
{
    int depth = 2 * log2(n);
    intro_sort_util(a, 0, n - 1, depth);
}

int main()
{
    int *a = rand_array(0, 10000, 20);
    intro_sort(a, 20);
    display(a, 20);
}