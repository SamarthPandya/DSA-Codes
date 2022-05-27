#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdio.h>
#include "tools.h"

using namespace std;

void insertion_sort(vector<float> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int j = i;
        while (j >= 0 && a[j] < a[j - 1])
        {
            float temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}
void bucket_sort(vector<float> &a, int from, int to)
{
    int n = a.size();
    vector<vector<float>> buckets;
    for (int i = 0; i < n; i++)
    {
        vector<float> temp;
        buckets.push_back(temp);
    }
    for (float i : a)
    {
        int mult = n * (i - from) / (to - from);
        buckets[mult].push_back(i);
    }
    a.clear();
    for (int i = 0; i < n; i++)
    {
        insertion_sort(buckets[i]);
    }
    for (auto bucket : buckets)
    {
        for (float i : bucket)
        {
            a.push_back(i);
        }
    }
}

vector<int> func(vector<int> &a)
{
    map<int, int> first, last;
    vector<int> out;
    for (int i = 0; i < a.size(); i++)
    {
        auto it = first.find(a[i]);
        if (it == first.end())
        {
            first.insert(pair<int, int>{a[i], i});
            last.insert(pair<int, int>{a[i], i});
        }
        last[a[i]] = i;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if(first[a[i]] == last[a[i]])
        {
            out.push_back(a[i]);
        }
        else if(first[a[i]] < last[a[i]])
        {
            if (first[a[i]] == -1)
            {
                continue;
            }
            else
            {
                out.push_back(a[i]);
                first[a[i]] = -1;
            }
        }
    }
    return out;
}

int main()
{
    vector<int> a = {1, 4, 3, 2, 3, 5, 3, 4}, b = func(a);
    for (int i : b)
    {
        cout << i << ' ';
    }
    cout << '\n';
}