#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\graphs\graphEssentials.h"
#include <bits/stdc++.h>

using namespace std;


int djikstra(int source, int dest, vector<vector<pair<int, int>>>g)
{
    vector<int>vis, dist;
    vis.assign(g.size(), 0);
    dist.assign(g.size(), INT_MAX);
    set<pair<int, int>>s;
    s.insert({0, source});
    dist[source - 1] = 0;
    while(s.size() > 0)
    {
        auto currPair = *(s.begin());
        int currNode = currPair.second;
        s.erase(s.begin());
        if(vis[currNode - 1])
        {
            continue;
        }
        vis[currNode - 1] = true;
        for(auto child : g[currNode - 1])
        {
            int childNode = child.first;
            int wt = child.second;
            if(dist[childNode] > wt + dist[currNode - 1])
            {
                dist[childNode] = dist[currNode - 1] + wt;
                s.insert({dist[childNode], childNode + 1});
            }
        }
    }
    for(int i = 0; i < g.size(); i++)
    {
        cout << i + 1 << ": " << dist[i] << '\n';
    }
    return dist[dest - 1];
}

int djikstraPath(int source, int dest, vector<vector<pair<int, int>>>g)
{
    vector<int>vis, dist;
    vector<int>parent;
    parent.assign(g.size(), -1);
    parent[source - 1] = source - 1;
    vis.assign(g.size(), 0);
    dist.assign(g.size(), INT_MAX);
    set<pair<int, int>>s;
    s.insert({ 0, source });
    dist[source - 1] = 0;
    while (s.size() > 0)
    {
        auto currPair = *(s.begin());
        int currNode = currPair.second;
        s.erase(s.begin());
        if (vis[currNode - 1])
        {
            continue;
        }
        vis[currNode - 1] = true;
        for (auto child : g[currNode - 1])
        {
            int childNode = child.first;
            int wt = child.second;
            if (dist[childNode] > wt + dist[currNode - 1])
            {
                dist[childNode] = dist[currNode - 1] + wt;
                parent[childNode] = currNode - 1;
                s.insert({ dist[childNode], childNode + 1 });
            }
        }
    }
    for (int i = 0; i < g.size(); i++)
    {
        cout << i + 1 << ": " << dist[i] << " || " << parent[i] + 1 << '\n';
    }
    vector<int>myPath;
    int temp = dest - 1;
    while(parent[temp] != temp)
    {
        myPath.push_back(temp);
        temp = parent[temp];
    }
    myPath.push_back(temp);
    reverse(myPath.begin(), myPath.end());
    for(int i : myPath)
    {
        cout << i + 1 << " ---> ";
    }
    cout << '\n';
    return dist[dest - 1];
}


int main()
{
    vector<vector<pair<int, int>>>g = weighted_graph_reader("tc2.txt");
}