#include <bits/stdc++.h>
#include "treeUtility.h"

using namespace std;

vector<vector<int>> zigzagLevelOrder(node* root) {
    vector<vector<int>>ans;
    if (root == nullptr)
    {
        return ans;
    }
    bool flag = true;

    vector<node*>q = { root };
    while (q.size() != 0)
    {
        vector<node*>updated;
        vector<int>level;
        if (flag == true)
        {
            for (int i = 0; i < q.size(); i++)
            {
                level.push_back(q[i]->val);
                if (q[i]->left != nullptr)
                    updated.insert(updated.begin(), q[i]->left);
                if (q[i]->right != nullptr)
                    updated.insert(updated.begin(), q[i]->right);
            }
            q = updated;
            ans.push_back(level);
            flag = false;
        }
        else
        {
            for (int i = 0; i < q.size(); i++)
            {
                level.push_back(q[i]->val);
                if (q[i]->right != nullptr)
                    updated.insert(updated.begin(), q[i]->right);
                if (q[i]->left != nullptr)
                    updated.insert(updated.begin(), q[i]->left);
            }
            q = updated;
            ans.push_back(level);
            flag = true;
        }
    }
    return ans;
}

int main()
{
    node *head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    vector<vector<int>> g = zigzagLevelOrder(head);
    for(auto list : g)
    {
        for(int i : list)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}