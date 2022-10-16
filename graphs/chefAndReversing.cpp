#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int minRevs(vector<vector<pair<int, int>>>g)
{
    int source = 0, dest = g.size() - 1;
    deque<pair<int, int>>q;
    vector<int>vis;
    vis.assign(g.size(), 0);
    vis[0] = 1;
    pair<int, int>firstPair = {source, 0};
    q.push_back(firstPair);
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop_front();
        int currNode = curr.first;
        int currLevel = curr.second;
        if(currNode == dest)
        {
            return currLevel;
        }
        for(auto childPair : g[currNode - 1])
        {
            if(vis[childPair.first] == 0)
            {
                pair<int, int>toBeAdded;
                if (childPair.second == 1)
                {
                    toBeAdded = { childPair.first, currLevel + 1 };
                    q.push_back(toBeAdded);
                }
                else
                {
                    toBeAdded = { childPair.first, currLevel };
                    q.push_front(toBeAdded);
                }
            }
        }
    }
}

int main()
{
    vector<vector<pair<int, int>>>g;
    int vertices, edges;
    cin >> vertices >> edges;
    for(int i = 0; i < edges; i++)
    {
        vector<pair<int, int>>temp;
        g.push_back(temp);
    }
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        pair<int, int>pair_no_penalty = {v - 1, 0}, pair_with_penalty = {u - 1, 1};
        g[u - 1].push_back(pair_no_penalty);
        g[v - 1].push_back(pair_with_penalty);
    }
}