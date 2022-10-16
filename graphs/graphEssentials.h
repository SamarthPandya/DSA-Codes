#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>reader(string filename)
{
    fstream file;
    int vertices, edges, v1, v2;
    vector<vector<int>> out;
    file.open(filename);
    file >> vertices >> edges;
    for(int i = 0; i < vertices; i++)
    {
        vector<int>temp;
        out.push_back(temp);
    }
    for(int i = 0; i < edges; i++)
    {
        file >> v1 >> v2;
        out[v1 - 1].push_back(v2 - 1);
        out[v2 - 1].push_back(v1 - 1);
    }
    file.close();
    return out;
}

vector<vector<int>>dreader(string filename)
{
    fstream file;
    int vertices, edges, v1, v2;
    vector<vector<int>> out;
    file.open(filename);
    file >> vertices >> edges;
    for (int i = 0; i < vertices; i++)
    {
        vector<int>temp;
        out.push_back(temp);
    }
    for (int i = 0; i < edges; i++)
    {
        file >> v1 >> v2;
        out[v1 - 1].push_back(v2 - 1);
    }
    file.close();
    return out;
}

void dfsUtil(int node, vector<vector<int>>g, vector<int>& vis, vector<int>&ans)
{
    vis[node - 1] = 1;
    ans.push_back(node);
    for(int child : g[node - 1])
    {
        if(!vis[child])
        {
            dfsUtil(child + 1, g, vis, ans);
        }
    }
}

vector<int>dfs(int node, vector<vector<int>>g)
{
    vector<int>vis, ans;
    vis.assign(g.size(), 0);
    dfsUtil(1, g, vis, ans);
    return ans;
}

vector<vector<int>> connectedComponents(vector<vector<int>>g)
{
    vector<int>vis;
    vector<vector<int>>ans;
    vis.assign(g.size(), 0);
    for(int i = 0; i < g.size(); i++)
    {
        if(!vis[i])
        {
            vector<int>temp;
            dfsUtil(i + 1, g, vis, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}

void isCyclicUtil(int node, int parent, vector<vector<int>>g, vector<int>&vis, bool&ans)
{
    vis[node - 1] = true;
    for(int child : g[node - 1])
    {
        if (!vis[child])
        {
            isCyclicUtil(child + 1, node, g, vis, ans);
        }
        else
        {
            if(child + 1 != parent)
            {
                ans = true;
                return;
            }
            else
            {
                continue;
            }
        }
    }
}

bool isCyclic(vector<vector<int>>g)
{
    vector<int>vis;
    vis.assign(g.size(), 0);
    bool ans = false;
    for(int i = 0; i < g.size(); i++)
    {
        if(vis[i] == 0)
        {
            bool temp = false;
            isCyclicUtil(i + 1, i + 1, g, vis, temp);
            ans = ans || temp;
        }
    }
    return ans;
}

vector<int>bfs(int node, vector<vector<int>>g)
{
    vector<int>vis;
    vector<int>ans;
    vis.assign(g.size(), 0);
    queue<int>q;
    q.push(node);
    vis[node  - 1] = true;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int child : g[curr - 1])
        {
            if(!vis[child])
            {
                vis[child] = true;
                q.push(child + 1);
            }
        }
    }
    return ans;
}

auto weighted_graph_reader(string s)
{
    fstream file;
    file.open(s);
    int vertices, edges;
    file >> vertices >> edges;
    vector<vector<pair<int, int>>>ans;
    for(int i = 0; i < vertices; i++)
    {
        vector<pair<int, int>>temp;
        ans.push_back(temp);
    }
    for(int i = 0; i < edges; i++)
    {
        int u, v, w;
        file >> u >> v >> w;
        pair<int, int>p1 = {v - 1, w}, p2 = {u - 1, w};
        ans[u - 1].push_back(p1);
        //ans[v - 1].push_back(p2);        
    }
    file.close();
    return ans;     
}

void finishingTimes_util(vector<vector<int>>g, int node, int &currentTime, vector<int>&vis, vector<int>&ft)
{
    vis[node - 1] = true;
    for(int child : g[node - 1])
    {
        if(vis[child])
        {
            continue;
        }
        else
        {
            currentTime++;
            finishingTimes_util(g, child + 1, currentTime, vis, ft);
        }
    }
    ft[node - 1] = currentTime;
    currentTime++;
}

vector<int>finishingTimes(int node, vector<vector<int>>g)
{
    vector<int>ans(g.size(), INT_MAX), vis(g.size(), 0);
    int x = 0;
    finishingTimes_util(g, node, x, vis, ans);
    return ans;
}