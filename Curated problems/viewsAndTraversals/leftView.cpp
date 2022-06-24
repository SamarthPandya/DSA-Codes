// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

/*
todo: Return the left view of a given tree
IDEA:
* Save the first value in each level.
* Sort these values level wise and return them.
*/

#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

vector<int> leftView(node* root)
{
    vector<int>ans;
    queue<node*>q;
    if (root == NULL)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        queue<node*>q1;
        while (!q.empty())
        {
            node* temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q1.push(temp->right);
            }
        }
        q = q1;
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
    vector<int>ans = leftView(head);
    for (int i : ans)
    {
        cout << i << ' ';
    }
}