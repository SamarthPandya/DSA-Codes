#include <bits/stdc++.h>
#include "treeUtility.h"

using namespace std;

void filler(node* head, int x, int y, vector<pair<int, pair<int, node*>>>& ans)
{
    if (head != NULL)
    {
        filler(head->left, x - 1, y + 1, ans);
        pair<int, node*>sec = { y, head };
        pair<int, pair<int, node*>>t = { x, sec };
        ans.push_back(t);
        filler(head->right, x + 1, y + 1, ans);
    }
}

vector<vector<int>>verticalOrder(node* head)
{
    vector<pair<int, pair<int, node*>>> v;
    vector<vector<int>> ans;
    filler(head, 0, 0, v);
    int i = 0, j;
    while (i < v.size())
    {
        j = i;
        vector<int>temp;
        while (v[j].first == v[i].first)
        {
            temp.push_back(v[j].second.second->val);
            j++;
        }
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
        i = j;
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
}