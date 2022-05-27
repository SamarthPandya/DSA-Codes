#include <bits/stdc++.h>
#include "tools.h"

void bubble_sort(int a[], int n)
{
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swapper(a[i], a[i + 1]);
                flag = true;
            }
        }
    }
}

int main()
{
    cout << "Hello world! ";
}