// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

/*
todo: Return the bottom view of a given tree
IDEA: For any horizontal distance from the root, save the latest
      element in level order traversal.

      Sort these values based on horizontal distances and return them.
*/

#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

vector<int>bottomView(node* head)
{
    vector<int>ans;
    if (head == NULL)
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
        // updating the map with latest element at the HorizDist
        auto it = m.find(currHD);
        if (it == m.end())
        {
            m.insert({ currHD, currNode->val });
        }
        else
        {
            m[currHD] = currNode->val;
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
    vector<int>ans = bottomView(head);
    for (int i : ans)
    {
        cout << i << ' ';
    }
}