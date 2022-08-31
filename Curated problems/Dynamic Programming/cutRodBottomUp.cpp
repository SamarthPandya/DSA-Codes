#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cutRodBottomUp(vector<int>p)
{
    int l = p.size();
    vector<int>profit;
    profit.assign(l + 1, -1);
    profit[0] = 0;
    for(int i = 1; i <= l; i++)
    {
        int q = INT_MIN;
        for(int j = 1; j <= i; j++)
        {
            q = max(q, profit[i - j] + p[j - 1]);
        }
        profit[i] = q;
    }
    return profit.back();
}

int main()
{
    vector<int>p = { 1, 5, 4, 20};
    cout << cutRodBottomUp(p);
}