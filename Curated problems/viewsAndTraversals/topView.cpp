#include <bits/stdc++.h>
#include "treeUtility.h"

using namespace std;

vector<int>topView(node *head)
{
    vector<int>ans;
    if(head == NULL)
    {
        return ans;
    }
    queue<pair<int, node*>>q; // pair{HorizDist, node}
    q.push({ 0, head }); // HD(root) = 0
    map<int, int>m;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int currHD = curr.first;
        node* currNode = curr.second;
        // updating the map with latest HorizDist if found
        auto it = m.find(currHD);
        if (it == m.end())
        {
            m.insert({ currHD, currNode->val });
        }
        // Pushing next level into queue
        if (currNode->left != NULL)
        {
            pair<int, node*>p = { currHD - 1, currNode->left };
            q.push(p);
        }
        if (currNode->right != NULL)
        {
            pair<int, node*> p = { currHD + 1, currNode->right };
            q.push(p);
        }
    }
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    node* head = new node(20);
    head->left = new node(8);
    head->right = new node(22);
    head->left->left = new node(5);
    head->left->right = new node(3);
    head->left->right->left = new node(10);
    head->right->left = new node(4);
    head->right->left->right = new node(14);
    head->right->right = new node(25);
    vector<int>ans = topView(head);
    for (int i : ans)
    {
        cout << i << ' ';
    }
}