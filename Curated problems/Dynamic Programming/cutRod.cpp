#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cutRodUtil(vector<int>p, int n, vector<int>& memo, int& c)
{
    if (n - 1 >= 0 && memo[n - 1] >= 0)
    {
        c++;
        return memo[n - 1];
    }
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int q = INT_MIN;
        for (int i = 1; i < n + 1; i++)
        {
            q = max(q, p[i - 1] + cutRodUtil(p, n - i, memo, c));
        }
        memo[n - 1] = q;
        return q;
    }
}

int cutRod(vector<int>p, int n)
{
    vector<int>m(n, -1);
    int k = 0;
    int l = cutRodUtil(p, n, m, k);
    return l;
}
int main()
{
    vector<int>p = { 1, 5, 4 };
    cout << cutRod(p, p.size());
}