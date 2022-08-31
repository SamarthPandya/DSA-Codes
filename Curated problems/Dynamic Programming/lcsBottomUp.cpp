#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> lcs(vector<int>a, vector<int>b)
{
    int m = a.size();
    int n = b.size();
    vector<vector<int>>c;
    for(int i = 0; i < n + 1; i++)
    {
        vector<int>rowVector;
        rowVector.assign(m + 1, -1);
        c.push_back(rowVector);
    }
    for(int i = 0; i < n + 1; i++)
    {
        c[i][0] = 0;
    }
    for(int j = 0; j < m + 1; j++)
    {
        c[0][j] = 0;    
    }
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < m + 1; j++)
        {
            if(a[i - 1] == b[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else
            {
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
            }
        }
    }
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < m + 1; j++)
        {
            if(a[j - 1] == b[i - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else
            {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    int i = n;
    int j = m;
    vector<int>ans;
    while(i != 0 && j != 0)
    {
        if(a[j - 1] == b[i - 1])
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
    reverse(ans.begin(), ans.end());
    return ans;
}


int main()
{
    vector<int>a = {1, 3, 2, 4, 2, 3}, b = {3, 2, 4, 3}, p = lcs(a, b);
    for(int i : p)
    {
        cout << i << ' ';
    }
}