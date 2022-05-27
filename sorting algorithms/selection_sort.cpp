#include <bits/stdc++.h>
#include "tools.h"

using namespace std;

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)            
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)        
        {
            if (a[j] < a[smallest])
            {
                smallest = j;
            }
        }// O(n)
        swapper(a[i], a[smallest]);
    } // O(n)
}//O(n^2)                                              

int main()
{
    int a[5] = {4, 3, 6, 3, 5};
    selection_sort(a, 5);
    display(a, 5);
}