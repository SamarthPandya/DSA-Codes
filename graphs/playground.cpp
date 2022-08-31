#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\graphs\graphEssentials.h"
#include <bits/stdc++.h>

using namespace std;

void isCyc(int node, int parent, vector<vector<int>>g, vector<int>& vis, bool& ans)
{
    vis[node - 1] = true;
    for (int child : g[node - 1])
    {
        if (vis[child] && child + 1 != parent)
        {
            ans = true;
            return;
        }
        if (!vis[child])
        {
            isCyc(child + 1, node, g, vis, ans);
        }
    }
}

void dfsComp(int node, vector<vector<int>>g, vector<int>& vis, vector<int>&v)
{
    vis[node - 1] = true;
    for(int child : g[node - 1])
    {
        if(!vis[child])
        {
            dfsComp(child + 1, g, vis, v);
        }
    }
    v.push_back(node);
}

bool func(vector<vector<int>>g)
{
    vector<int>vis;
    vis.assign(g.size(), false);
    bool ans = false;
    for (int i = 0; i < g.size(); i++)
    {
        if (!vis[i])
        {
            isCyc(i + 1, i + 1, g, vis, ans);
            if (ans == true)
            {
                return true;
            }
        }
    }
    return false;
}

void displayComponents(vector<vector<int>>g)
{
    vector<vector<int>>comps;
    vector<int>vis;
    vis.assign(g.size(), 0);
    for(int i = 0; i < g.size(); i++)
    {
        if(!vis[i])
        {
            vector<int>temp;
            dfsComp(i + 1, g, vis, temp);
            comps.push_back(temp);
        }
    }
    for(auto li : comps)
    {
        cout << '\n';
        for(int i : li)
        {
            cout << i << ' ';
        }
    }
}

void subTreeSum(int root, int parent, vector<vector<int>>g, unordered_map<int, int>&v)
{
    for(int child : g[root - 1])
    {
        if(child + 1 == parent)
        {
            continue;
        }
        subTreeSum(child + 1, root, g, v);
    }
    int s = 0;
    for(int child : g[root - 1])
    {
        if(child + 1 != parent)
        {
            s = s + v[child + 1] + child + 1;
        }
    }
    v.insert({root, s});
}

void dfsTree(int node, int parent, vector<vector<int>>g, map<int, int>&v)
{
    for(int child : g[node - 1])
    {
        if(child + 1 != parent)
        {
            v.insert({ child + 1, 1 + v[node]});
            dfsTree(child + 1, node, g, v);
        }
    }
}

int diameter(vector<vector<int>>g)
{
    map<int, int>v;
    v.insert({1, 0});
    dfsTree(1, 1, g, v);
    int farthestVertex = v.end()->first;
    v.clear();
    v.insert({farthestVertex, 0});
    dfsTree(farthestVertex, farthestVertex, g, v);
    int s = 0;
    for (auto i : v)
    {
        s = max(s, i.second);
    }
    return s;
}

void parentFinder(int root, int parent, vector<vector<int>>g, vector<int>&par)
{
    par[root - 1] = parent;
    for(int child : g[root - 1])
    {
        if(child + 1 != parent)
        {
            parentFinder(child + 1, root, g, par);
        }
    }    
}

vector<int> pathFinder(int u, int v, vector<vector<int>>g)
{
    vector<int>par;
    par.assign(g.size(), 0);
    parentFinder(u, u, g, par);
    vector<int>ans;
    int i = v - 1;
    while (par[i] != i + 1)
    {
        ans.push_back(i + 1);
        i = par[i] - 1;
    }
    ans.push_back(i + 1);
    reverse(ans.begin(), ans.end());
    return ans;
}

int lca(int root, int u, int v, vector<vector<int>>g)
{
    vector<int>v1 = pathFinder(u, root, g);
    vector<int>v2 = pathFinder(v, root, g);
    unordered_map<int, bool>m;
    for(int i : v1)
    {
        m.insert({i, true});
    }
    for(int i = 0; i < v2.size(); i++)
    {
        auto it = m.find(v2[i]);
        if(it != m.end())
        {
            return v2[i];
        }
    }
}

void util(int root, int parent, vector<vector<int>>g, vector<int>&v)
{
    for(int child : g[root - 1])
    {
        if(child + 1 == parent)
        {
            continue;
        }
        util(child + 1, root, g, v);
    }
    int s = root;
    for(int child : g[root - 1])
    {
        if(child + 1 != parent)
        {
            s = s + v[child];
        }
    }
    v[root - 1] = s;
}

void fillColorsUtil(int node, int parent, vector<vector<int>>&g, vector<int>&nodeColors)
{
    if(node == parent)
    {
        nodeColors[node - 1] = 1;
    }
    else
    {
        nodeColors[node  - 1] = -1 * nodeColors[parent - 1];
    }
    for(int child : g[node - 1])
    {
        if(!nodeColors[child])
        {
            fillColorsUtil(child + 1, node, g, nodeColors);
        }
    }
}

vector<int> fillColors(vector<vector<int>>g)
{
    vector<int>cols;
    cols.assign(g.size(), 0);
    for(int i = 0; i < g.size(); i++)
    {
        if(cols[i] == 0)
        {
            fillColorsUtil(i + 1, i + 1, g, cols);
        }
    }
    return cols;
}


bool isBipartite(vector<vector<int>>g)
{
    vector<int>cols = fillColors(g);
    for(int i = 0; i < g.size(); i++)
    {
        cout << i + 1 << ": " << cols[i] << '\n';
    }
    for(int i = 0; i < g.size(); i++)
    {
        for(int child : g[i])
        {
            if(cols[child] == cols[i])
            {
                cout << child + 1 << ' ' << i + 1 << '\n';
                return false;
            }
        }
    }
    return true;
}

int minPathLen(int source, int destination, vector<vector<int>>g)
{
    queue<pair<int, int>>q;
    vector<int>vis;
    vis.assign(g.size(), 0);
    q.push({source, 0});
    vis[source - 1] = true;
    while(!q.empty())
    {
        auto currPair = q.front();
        q.pop();
        int currNode = currPair.first;
        int currLevel = currPair.second;
        if(currNode == destination)
        {
            return currLevel;
        }
        for(int child : g[currNode - 1])
        {
            if(!vis[child])
            {
                vis[child] = true;
                q.push({child + 1, currLevel + 1});
            }
        }
    }
}

int shortestPath(int i, int j, int x, int y)
{
    map<pair<int, int>, bool>vis;
    queue<pair<pair<int, int>, int>>q;
    q.push({{i, j}, 0});
    vis[{i, j}] = true;
    while(!q.empty())
    {
        auto currPair = q.front();
        q.pop();
        auto currPoint = currPair.first;
        int currLevel = currPair.second;
        int u = currPoint.first;
        int v = currPoint.second;
        cout << u << ", " << v <<  " - " << currLevel << '\n';
        if(u == x && v == y)
        {
            return currLevel;
        }
        if(vis.find({i - 2, j + 1}) == vis.end() && i - 2 >= 0 && j + 1 < 8)
        {
            vis[{i - 2, j + 1}] = true;
            q.push({ {i - 2, j + 1}, currLevel + 1 });
        }
        if (vis.find({i - 1, j + 2}) == vis.end() && i - 1 >= 0 && j + 2 < 8)
        {
            cout << "pushing" << '\n';
            vis[{i - 1, j + 2}] = true;
            q.push({{i - 1, j + 2}, currLevel + 1 });
        }
        if (vis.find({ i + 1, j + 2 }) == vis.end() && i + 1 < 8 && j + 2 < 8)
        {
            vis[{i + 1, j + 2}] = true;
            q.push({ {i + 1, j + 2}, currLevel + 1 });
        }
        if (vis.find({ i + 2, j + 1 }) == vis.end() && i + 2 < 8 && j + 1 < 8)
        {
            vis[{i + 2, j + 1}] = true;
            q.push({ {i + 2, j + 1}, currLevel + 1 });
        }
        if (vis.find({ i + 2, j - 1 }) == vis.end() && i + 2 < 8 && j - 1 >= 0)
        {
            vis[{i + 2, j - 1}] = true;
            q.push({ {i + 2, j - 1}, currLevel + 1 });
        }
        if (vis.find({ i + 1, j - 2 }) == vis.end() && i + 1 < 8 && j - 2 >= 0)
        {
            vis[{i + 1, j - 2}] = true;
            q.push({ {i + 1, j - 2}, currLevel + 1 });
        }
        if (vis.find({ i - 1, j - 2 }) == vis.end() && i - 1 >= 0 && j - 2 >= 0)
        {
            vis[{i - 1, j - 2}] = true;
            q.push({ {i - 1, j - 2}, currLevel + 1 });
        }
        if (vis.find({ i - 2, j - 1 }) == vis.end() && i - 2 >= 0 && j - 1 >= 0)
        {
            vis[{i - 2, j - 1}] = true;
            q.push({ {i - 2, j - 1}, currLevel + 1 });
        }
    }
}

int main()
{
    cout << shortestPath(0, 0, -1, 2);
}