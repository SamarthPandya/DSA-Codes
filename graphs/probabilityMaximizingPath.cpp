#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\graphs\graphEssentials.h"
#include <bits/stdc++.h>

using namespace std;


double probabilityMaximizer(vector<vector<pair<int, double>>>g)
{
    vector<int>vis(g.size(), 0);
    vector<double>dist(g.size(), 0.0);
    priority_queue<pair<double, int>>q;
    dist[0] = 1.0;
    q.push({1.0, 1});
    while(!q.empty())
    {
        auto currPair = q.top();
        int currNode = currPair.second;
        q.pop();
        if(vis[currNode - 1])
        {
            continue;
        }
        vis[currNode - 1] = true;
        for(auto childPair : g[currNode - 1])
        {
            int childNode = childPair.first;
            double wt = childPair.second;
            if(dist[childNode] < dist[currNode - 1] * wt)
            {
                dist[childNode] = dist[currNode - 1] * wt;
                q.push({dist[childNode], childNode + 1});
            }
        }
    }
}