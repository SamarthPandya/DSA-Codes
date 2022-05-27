#include <bits/stdc++.h>
#include "tools.h"

using namespace std;

void counting_sort(int a[], int n)
{
    int max_element = a[largest(a, 0, n - 1)];
    int hash_table[max_element + 1] = {0}, b[n];
    for (int i = 0; i < n; i++)
    {
        hash_table[a[i]]++;
    }
    for (int i = 1; i < max_element + 1; i++)
    {
        hash_table[i] += hash_table[i - 1];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        b[hash_table[a[i]] - 1] = a[i];
        hash_table[a[i]]--;
    }
    for(int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    int a[4] = {1, 0, 4, 1};
    counting_sort(a, 4);
    display(a, 4);
}