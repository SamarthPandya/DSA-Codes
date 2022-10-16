#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\graphs\graphEssentials.h"
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>fw(vector<vector<pair<int, int>>>g)
{
    int n = g.size();
    vector<vector<int>>dp(g.size());
    for(int i = 0; i < g.size(); i++)
    {
        dp[i].assign(g.size(), INT_MAX);
    }

    
    // using no intermediate nodes
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(auto p : g[i])
        {
            dp[i][p.first] = p.second;
        }   
    }

    // using 0 to k-1 as intermediate nodes;
    for(int k = 0; k < n; k++)
    { 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // if minimization possible
                if(dp[i][k] != INT_MAX && dp[k][j] != INT_MAX)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    return dp;
}

bool isValid(int i, int j, int rows, int cols)
{
    return (i >= 0 && i < rows) && (j >= 0 && j < cols);
}

vector<vector<pair<int, int>>> show(vector<vector<int>>matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    vector<pair<int, int>>directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    vector<vector<pair<int, int>>>g;
    for (int i = 0; i < rows * cols; i++)
    {
        vector<pair<int, int>>temp;
        g.push_back(temp);
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (auto dir : directions)
            {
                int dx = dir.first, dy = dir.second;
                if (isValid(i + dx, j + dy, rows, cols))
                {
                    if (matrix[i + dx][j + dy] > matrix[i][j])
                    {
                        g[(i * cols) + j].push_back({ 1,  ((i + dx) * cols) + j + dy});
                    }
                }
            }
        }
    }
    for(int i = 0; i < g.size(); i++)
    {
        cout << i << ": ";
        for(auto k : g[i])
        {
            cout << k.second << "  ";
        }
        cout << '\n';
    }
}

int main()
{
    // vector<vector<pair<int, int>>>g = weighted_graph_reader("tc2.txt");
    // auto m = fw(g);
    // for(auto li : m)
    // {
    //     for(int i : li)
    //     {
    //         cout << i << ' ';
    //     }
    //     cout << '\n';
    // }
    vector<vector<int>>m;
    vector<int>a = {1, 3, 5}, b = {0, 4, 6}, c = {2, 2, 9};
    m = {a, b, c};
    show(m);
}