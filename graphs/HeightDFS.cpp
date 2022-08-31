#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\graphs\graphEssentials.h"
#include <bits/stdc++.h>

using namespace std;

void dfsOnTree(int node, int parent, vector<vector<int>>g, vector<int>&h)
{
    if(node != 1)
    {
        h[node - 1] = h[parent - 1] + 1;
    }
    for(int child : g[node - 1])
    {
        if(child + 1 != parent)
        {
            dfsOnTree(child + 1, node, g, h);
        }
    }
}

vector<int>preComputeHeight(int root, vector<vector<int>>g)
{
    vector<int>h;
    h.assign(g.size(), 0);
    dfsOnTree(1, 1, g, h);
    return h;
}

int main()
{
    vector<vector<int>>g = reader("tc1.txt");
    vector<int>h = preComputeHeight(1, g);
    for(int i = 0; i < g.size(); i++)
    {
        cout << i + 1 << ": " << h[i] << '\n';
    }
}