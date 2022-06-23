// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*
todo: Return the zig zag level order traversal of a given tree
*/

#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(node* root) {
        vector<vector<int>>ans;
        if (root == nullptr)
        {
            return ans;
        }
        bool flag = true; // tracking zig-zag

        vector<node*>q = { root };
        while (q.size() != 0)
        {
            vector<node*>updated;
            vector<int>level;
            if (flag == true) // time for zig
            {
                for (int i = 0; i < q.size(); i++)
                {
                    level.push_back(q[i]->val);
                    // dry run to understand
                    if (q[i]->left != nullptr)
                        updated.insert(updated.begin(), q[i]->left);
                    if (q[i]->right != nullptr)
                        updated.insert(updated.begin(), q[i]->right);
                }
                flag = false;
            }
            else // time for zag
            {
                for (int i = 0; i < q.size(); i++)
                {
                    level.push_back(q[i]->val);
                    // dry run to understand
                    if (q[i]->right != nullptr)
                        updated.insert(updated.begin(), q[i]->right);
                    if (q[i]->left != nullptr)
                        updated.insert(updated.begin(), q[i]->left);
                }
                
                flag = true;
            }
            q = updated; // updating to next level
            ans.push_back(level); // this level is complete
        }
        return ans;
    }
};

// driver code
int main()
{
    node* head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    Solution s;
    vector<vector<int>> g = s.zigzagLevelOrder(head);
    for (auto list : g)
    {
        for (int i : list)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}