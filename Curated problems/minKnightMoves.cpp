#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isValid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

int minMoves(int i, int j, int x, int y)
{
    vector<vector<int>>vis;
    for(int i = 0; i < 8; i++)
    {
        vector<int>temp;
        temp.assign(8, 0);
        vis.push_back(temp);
    }
    pair<int, int>a1 = {-2, 1}, a2 = {-2, -1}, a3 = {2, 1}, a4 = {2, -1}, a5 = {-1, 2}, a6 = {-1, -2}, a7 = {1, 2}, a8 = {1, -2};
    vector<pair<int, int>>moves = {a1, a2, a3, a4, a5, a6, a7, a8};
    queue<pair<pair<int, int>, int>>q;
    pair<int, int>start = {i, j};
    pair<pair<int, int>, int>first_push = {start, 0};
    vis[i][j] = 1;
    q.push(first_push);
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int curr_x = curr.first.first;
        int curr_y = curr.first.second;
        int curr_level = curr.second;
        cout << "At (" << curr_x << ", " << curr_y << ")" << " on level: " << curr_level << '\n';
        if(curr_x == x && curr_y == y)
        {
            return curr_level;
        }
        for(auto move : moves)
        {
            int u = move.first;
            int v = move.second;
            if (isValid(curr_x + u, curr_y + v)&& vis[curr_x + u][curr_y + v] == 0)
            {
                vis[curr_x + u][curr_y + v] = 1;
                pair<int, int>newPoint = {curr_x + u, curr_y + v};
                pair<pair<int, int>, int>toBePushed = {newPoint, curr_level + 1};
                q.push(toBePushed);
            }
        }
    } 
}

int main()
{
    cout << minMoves(5, 5, 6, 7);
}