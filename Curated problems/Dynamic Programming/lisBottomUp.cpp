//longest increading subsequence
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lisBottomUp(vector<int>a) // only for value of optimal sol
{
    int n = a.size();
    vector<int>memo;
    memo.assign(n, 1);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                memo[i] = max(memo[i], 1 + memo[j]);
            }
        }
    }
    int ans = memo[0];
    for(int i = 1; i < n; i++)
    {
        if(memo[i] > ans)
        {
            ans = memo[i];
        }
    }
    return ans;
}

auto lis(vector<int>a) // for the optimal solution itself.
{
    int n = a.size();
    vector<pair<int, vector<int>>>memo;
    for(int i = 0; i < n; i++)
    {
        vector<int>temp;
        memo.push_back({1, temp});
    }
    memo[0].second.push_back(a[0]);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            {
                if(1 + memo[j].first > memo[i].first)
                {
                    vector<int>temp = memo[j].second;
                    temp.push_back(a[i]);
                    memo[i].second = temp;
                    memo[i].first = 1 + memo[j].first;
                }
            }
        }
    }
    auto ans = memo[0];
    for(int i = 1; i < n; i++)
    {
        if(memo[i].first > ans.first)
        {
            ans = memo[i];
        }
    }
    return ans;
}

int main()
{
    vector<int>a = {2, 4, 2, 4, 6, 21, 3, 2, 4, 5, 6, 3, 4};
    auto k = lis(a);
    cout << k.first;
    cout << '\n';
    for(int i : k.second)
    {
        cout << i << ' ';
    }
}