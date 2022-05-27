#include <iostream>
#include "tools.h"

using namespace std;

void merger(int a[], int left, int mid, int right)
{
    if (left < right)
    {
        int l1 = mid - left + 1, l2 = right - mid;
        int p[l1], q[l2];
        for (int i = left; i <= mid; i++)
        {
            p[i - left] = a[i];
        }
        for (int i = mid + 1; i <= right; i++)
        {
            q[i - mid - 1] = a[i];
        }
        int i = 0, j = 0, k = left;
        while (i < l1 && j < l2)
        {
            if (p[i] <= q[j])
            {
                a[k++] = p[i++];
            }
            else
            {
                a[k++] = q[j++];
            }
        }
        while (i < l1)
        {
            a[k++] = p[i++];
        }
        while (j < l2)
        {
            a[k++] = q[j++];
        }
    }
} // O(n)

void merge_sort(int a[], int i, int j)
{
    if (i < j)
    {
        int mid = i + (j - i) / 2;
        merge_sort(a, i, mid);
        merge_sort(a, mid + 1, j);
        merger(a, i, mid, j);
    }
} // O(nlogn)

int main()
{
    int x;
    cout << "Enter: ";
    cin >> x;
    cout << ' ' << x << '\n';
}