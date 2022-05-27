#include <bits/stdc++.h>
#include "tools.h"

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)          
    {
        int j = i;
        while (a[j] < a[j - 1] && j > 0)  
        {
            swapper(a[j], a[j - 1]);
            j--;
        } //O(n)
    } // O(n)
} // O(n^2)                                        

int main()
{
    int a[5] = {5, 4, 3, 2, 1};
    insertion_sort(a, 5);
    display(a, 5);
}