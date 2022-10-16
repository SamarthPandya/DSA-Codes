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

int bfs01(vector<vector<pair<int, int>>>g, int source, int dest)
{
    vector<int>lev(g.size(), INT_MAX);
    deque<int>q;
    q.push_back(source - 1);
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop_front();
        for(auto childPair : g[currNode])
        {
            int childNode = childPair.first;
            if(lev[childNode] > lev[currNode] + childPair.second)
            {
                lev[childNode] = lev[currNode] + childPair.second;
                if(childPair.second == 0)
                {
                    q.push_front(childNode);
                }
                else
                {
                    q.push_back(childNode);
                }
            }
        }
    }
    return lev[source - 1];
}

auto specialReader(string s)
{
    fstream file;
    vector<vector<pair<int, int>>>g;
    file.open(s);
    int vertices, edges;
    file >> vertices >> edges;
    for (int i = 0; i < vertices; i++)
    {
        vector<pair<int, int>>temp;
        g.push_back(temp);
    }
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        file >> u >> v;
        pair<int, int>pair_no_penalty = { v - 1, 0 }, pair_with_penalty = { u - 1, 1 };
        g[u - 1].push_back(pair_no_penalty);
        g[v - 1].push_back(pair_with_penalty);
    }
    return g;
}

int specialBFS(vector<vector<pair<int, int>>>g)
{
    int source = 0, dest = g.size() - 1;
    deque<pair<int, int>>q;
    vector<int>vis;
    vis.assign(g.size(), 0);
    vis[0] = 1;
    pair<int, int>firstPair = { source, 0 };
    q.push_back(firstPair);
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop_front();
        int currNode = curr.first;
        int currLevel = curr.second;
        cout << currNode + 1 << ": " << currLevel << '\n';
        if (currNode == dest)
        {
            return currLevel;
        }
        for (auto childPair : g[currNode])
        {
            if (vis[childPair.first] == 0)
            {
                pair<int, int>toBeAdded;
                vis[childPair.first] = 1;
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

void multibfs(vector<vector<int>>g, vector<int>sources)
{
    vector<int>lev;
    lev.assign(g.size() , INT_MAX);
    queue<pair<int, int>>q;
    for(int i : sources)
    {
        q.push({i, 0});
        lev[i - 1] = 0;
    }
    while(!q.empty())
    {
        auto currPair = q.front();
        q.pop();
        int currNode = currPair.first;
        int currLevel = currPair.second;
        cout << currNode << " at " << currLevel << '\n';
        for(int child : g[currNode - 1])
        {
            if(lev[child] > 1 + lev[currNode - 1])
            {
                lev[child] = 1 + lev[currNode - 1];
                q.push({child + 1, lev[currNode - 1] + 1});
            }
        }
    }
}

bool dcyclic_util(int node, vector<vector<int>>g, vector<int>&vis, vector<int>&st)
{
    vis[node] = true;
    st[node] = true;
    for(int child : g[node])
    {
        if(!vis[child])
        {
            if(dcyclic_util(child, g, vis, st))
            {
                return true;
            }
        }
        else if(st[child])
        {
            return true;
        }
    }
    st[node] = false;
    return false;
}

bool dcyclic(vector<vector<int>>g)
{
    vector<int>vis(g.size(), 0), st(g.size(), 0);
    for(int i = 0; i < g.size(); i++)
    {
        if(!vis[i])
        {
            if(dcyclic_util(i, g, vis, st))
            {
                return true;
            }
        }
    }
    return false;
}

void dfsInTree(int node, int parent, vector<vector<int>>g)
{
    cout << node << ' ';
    for(int child : g[node - 1])
    {
        if(child + 1 == parent)
        {
            continue;
        }
        dfsInTree(child + 1, node, g);
    }
}

void heightInTree(int root, int parent, vector<vector<int>>g, vector<int>&h, vector<int>&d)
{
    if(root == parent)
    {
        d[root - 1] = 0;
    }
    else
    {
        d[root - 1] = 1 + d[parent - 1];
    }
    for(int child : g[root - 1])
    {
        if(child + 1 == parent)
        {
            continue;
        }
        heightInTree(child + 1, root, g, h, d);
    }
    int hTemp = -1;
    for(int child : g[root - 1])
    {
        if(child + 1 != parent && h[child] > hTemp)
        {
            hTemp = h[child];
        }
    }
    h[root - 1] = hTemp + 1;   
}

void subTreeSum(int node, int parent, vector<vector<int>>g, vector<int>&s)
{
    for(int child : g[node - 1])
    {
        if(child + 1 != parent)
        {
            subTreeSum(child + 1, node, g, s);
        }
    }
    int su = 0;
    for(int child : g[node - 1])
    {
        if(child + 1 != parent)
        {
            su = su + s[child] + ((child + 1) % 2 == 0 ? 1 : 0);
        }
    }
    s[node - 1] = su;
}

vector<int>bfsInG(int source, vector<vector<int>>g)
{
    vector<int>ans;
    queue<int>q;
    q.push(source - 1);
    vector<int>vis(g.size(), 0);
    vis[source - 1] = true;
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        ans.push_back(currNode + 1);
        for(int child : g[currNode])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
    return ans;
}

vector<int>bfsInTree(int source, vector<vector<int>>g)
{
    queue<pair<int, int>>q; // {node, parent}
    q.push({source - 1, source - 1});
    vector<int>ans;
    while(!q.empty())
    {
        auto currPair = q.front();
        q.pop();
        int currNode = currPair.first;
        int parent = currPair.second;
        ans.push_back(currNode + 1);
        for(int child : g[currNode])
        {
            if(child != parent)
            {
                q.push({child, currNode});
            }
        }
    }
    return ans;
}

vector<int>distBFS(int source, vector<vector<int>>g)
{
    vector<int>ans(g.size(), 0), vis(g.size(), 0);
    ans[source - 1] = 0;
    vis[source - 1] = true;
    queue<pair<int, int>>q; // {node, dist}
    q.push({source - 1, 0});
    while(!q.empty())
    {
        auto currPair = q.front();
        q.pop();
        int currNode = currPair.first;
        int currDist = currPair.second;
        for(int child : g[currNode])
        {
            if(!vis[child])
            {
                vis[child] = true;
                ans[child] = 1 + currDist;
                q.push({child, ans[child]});
            }
        }
    }
    return ans;
}

int ddiam(vector<vector<int>>g)
{
    vector<int>m = distBFS(1, g);
    int mi = INT_MIN, ind;
    for(int i = 0; i < m.size(); i++)
    {
        if(m[i] > mi)
        {
            ind = i + 1;
        }
    }
    m = distBFS(ind, g);
    int ans = INT_MIN, k;
    for(int i = 0; i < m.size(); i++)
    {
        cout << i + 1 << ": " << m[i] << '\n';
        if(m[i] > ans)
        {
            ans = m[i];
            k = i + 1;
        }
    }
    cout << "\nFrom " << ind << " to " << k << '\n';
    return ans;
}

void findParent(int node, int parent, vector<vector<int>>g, vector<int>&p)
{
    p[node - 1] = parent - 1;
    for(int child : g[node - 1])
    {
        if(child + 1 != parent)
        {
            findParent(child + 1, node, g, p);
        }
    }
}

vector<int>pathGenerator(int node, vector<int>p)
{
    vector<int>ans;
    int temp = node - 1;
    while(p[temp] != temp)
    {
        ans.insert(ans.begin(), temp);
        temp = p[temp];
    }
    ans.insert(ans.begin(), p[temp]);
    return ans;
}

int lowestCA(int node1, int node2, vector<vector<int>>g)
{
    vector<int>p(g.size(), 0);
    findParent(1, 1, g, p);
    vector<int>a = pathGenerator(node1, p), b = pathGenerator(node2, p);
    cout << '\n';
    for(int i : a)
    {
        cout << i + 1 << ' ';
    }
    cout << '\n';
    for (int i : b)
    {
        cout << i + 1 << ' ';
    }
    int ans;
    for(int i = 0; i < p.size(); i++)
    {
        if(a[i] != b[i])
        {
            ans = a[i - 1];
            break;
        }
    }
    return ans + 1;
}

bool checkPrime(int a)
{
    if(a <= 1)
    {
        return false;
    }
    for(int i = 2; i <= a/2; i++)
    {
        if(a % i == 0)
        {
            return false;
        }
    }
    return true;
}

void countPrime(int node, int parent, vector<vector<int>>g, vector<int>&p)
{
    for(int child : g[node - 1])
    {
        if(child + 1 != parent)
        {
            countPrime(child + 1, node, g, p);
        }
    }
    int s = checkPrime(node) ? 1 : 0;
    for(int i : g[node - 1])
    {
        s = s + p[i];
    }
    p[node - 1] = s;
}

int maxPrimeProduct(vector<vector<int>>g)
{
    vector<int>p(g.size(), 0);
    countPrime(1, 1, g, p);
    int tot = p[0];
    int ans = INT_MIN;
    for(int i = 0; i < g.size(); i++)
    {
        ans = max(ans, p[i] * (tot - p[i]));
    }
    return ans;
}

void djj(int source, vector<vector<pair<int, int>>>g)
{
    vector<int>dist(g.size(), INT_MAX), vis(g.size(), 0);
    set<pair<int, int>>s;
    dist[source - 1] = 0;
    s.insert({0, source - 1});
    while(s.size())
    {
        auto minPair = *(s.begin());
        s.erase(s.begin());
        int minNode = minPair.second;
        if(vis[minNode])
        {
            continue;
        }
        for(auto childPair : g[minNode])
        {
            int childNode = childPair.first;
            int wt = childPair.second;
            if(dist[childNode] > dist[minNode] + wt)
            {
                dist[childNode] = dist[minNode] + wt;
                s.insert({dist[childNode], childNode});
            }
        }
    }
    cout << '\n';
    for(int i = 0; i < g.size(); i++)
    {
        cout << i + 1 << ": " << dist[i] << '\n';
    }
}

int main()
{
    string a = "0-0", b = "0-1", c = "2-0", d = "1-4";
    vector<string>p = {a, b, c, d};
    int h[49] = {0};
    for(int i = 0; i < p.size(); i++)
    {
        int u = p[i][0] - 48;
        int v = p[i][2] - 48;
        if (u > v)
        {
            swap(u, v);
        }
        h[7 * u + v] = 1;
    }
    string ans;
    for(int i = 0; i < 48; i++)
    {
        if(!h[i])
        {
            int m = i % 7;
            int n = i/7;
            char a = m + 48;
            char b = n + 48;
            ans += a;
            ans += '-';
            ans += b;
            break;
        }
    }
    cout << ans;
}