#include "tools.h"
#include <math.h>

void counting_sort_util(int a[], int n, int m)
{
    int hasher[10] = {0};
    for (int i = 0; i < n; i++)
    {
        hasher[(int)(a[i] / pow(10, m)) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        hasher[i] = hasher[i] + hasher[i - 1];
    }
    int b[n];
    for (int i = n - 1; i >= 0; i--)
    {
        b[hasher[(int)(a[i] / pow(10, m)) % 10] - 1] = a[i];
        hasher[(int)(a[i] / pow(10, m)) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

void radix_sort(int a[], int n)
{
    int k = a[largest(a, 0, n - 1)], largest_power = -1;
    while (k != 0)
    {
        k = k / 10;
        largest_power++;
    }
    cout << largest_power;
    for (int i = 0; i <= largest_power; i++)
    {
        counting_sort_util(a, n, i);
    }
}

int main()
{
    int *a = rand_array(0, 20, 20);
    display(a, 20);
    radix_sort(a, 20);
    display(a, 20);
}