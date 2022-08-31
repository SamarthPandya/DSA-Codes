#include <bits/stdc++.h>

using namespace std;

int lcsUtil(vector<int>a, vector<int>b, int i, int j, vector<vector<int>>&dp)
{
    int temp;
    if(i >= 0 && j >= 0 && dp[i][j] >= 0)
    {
        return dp[i][j];
    }
    else
    {
        if(a[j - 1] == b[i - 1])
        {
            temp = 1 + lcsUtil(a, b, i - 1, j - 1, dp);
        }
        else
        {
            temp = max(lcsUtil(a, b, i - 1, j, dp), lcsUtil(a, b, i, j - 1, dp));
        }
    }
    dp[i][j] = temp;
    return temp;
}

vector<int>lcsTopDown(vector<int>a, vector<int>b)
{
    int m = a.size();
    int n = b.size();
    vector<vector<int>>c;
    for (int i = 0; i < n + 1; i++)
    {
        vector<int>rowVector;
        rowVector.assign(m + 1, -1);
        c.push_back(rowVector);
    }
    for (int i = 0; i < n + 1; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 0; j < m + 1; j++)
    {
        c[0][j] = 0;
    }
    lcsUtil(a, b, m, n, c);
    vector<int>ans;
    int i = n;
    int j = m;
    while(i != 0 && j != 0)
    {
        if(a[i - 1] == b[j - 1])
        {
            ans.push_back(a[j - 1]);
            i--;
            j--;
        }
        else
        {
            if(c[i - 1][j] > c[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    return ans;
    reverse(ans.begin(), ans.end());
}

int main()
{
    vector<int>a = {1, 4, 2, 3}, b = {0, 3, 2, 3}, p = lcsTopDown(a, b);
    for(int i : p)
    {
        cout << i << ' ';
    }
}