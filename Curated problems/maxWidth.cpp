#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

int maxWidth(node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    vector<node*>g;
    g.push_back(head);
    int ans = 1, currLev = 1, temp;
    while(g.size() != 0)
    {
        int penalty = 0;
        int si = 0, ei;
        for(auto i = g.begin(); i != g.end(); i++)
        {
            if((*i)->left == NULL && (*i)->right == NULL)
            {
                si = si + 2;
                continue;
            }
            else if((*i)->left == NULL && (*i)->right != NULL)
            {
                si++;
                break;
            }
            else
            {
                break;
            }
        }
        vector<node*>g1;
        for(auto i : g)
        {
            if(i->left != NULL)
            {
                g1.push_back(i->left);
            }
            if (i->right != NULL)
            {
                g1.push_back(i->right);
            }
        }
        g = g1;
        if(g.size() == 0)
        {
            break;
        }
        temp = pow(2, currLev) - penalty;
        currLev++;
        cout << temp << '\n';
        if(temp > ans)
        {
            ans = temp;
        }
    }
    return ans;
}





int main()
{
    node* head = new node(1);
    head->left = new node(3);
    head->right = new node(2);
    head->left->left = new node(5);
    /*head->right->right = new node(9);
    head->left->left->left = new node(6);
    head->right->right->left = new node(7);*/
    cout << diameter(head);
}