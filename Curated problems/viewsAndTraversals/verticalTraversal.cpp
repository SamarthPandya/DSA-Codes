#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

vector<int>verticalTraversal(Node*root)
{
    vector<int>ans;
    if(!root)
    {
        return ans;
    }
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    map<int, vector<int>>m;
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        Node* currNode = curr.first;
        int currHD = curr.second;
        if(m.find(currHD) == m.end())
        {
            vector<int>temp = {currNode->val};
            m[currHD] = temp;
        }
        else
        {
            m[currHD].push_back(currNode->val);
        }
        if(currNode->left)
        {
            q.push({currNode->left, currHD - 1});
        }
        if(currNode->right)
        {
            q.push({currNode->right, currHD + 1});
        }
    }
    for(auto it: m)
    {
        for(int j : it.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

int main()
{
    Node*head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    head->left->right = new node(4);
    head->right->right = new node(90);
    vector<int>v = verticalTraversal(head);
    for(int i : v)
    {
        cout << i << ' ';
    }
}