#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

auto insertNode(node *head, int key)
{
    if(head == NULL)
    {
        node* tobeInserted = new node(key);
        return tobeInserted;
    }
    if(head->val < key)
    {
        head->right = insertNode(head->right, key);
    }
    else
    {
        head->left = insertNode(head->left, key);
    }
    int bf = balanceFactor(head);
    if(bf > 1)
    {
        if(balanceFactor(head->left) >= 0)
        {
            return rrRotation(head);
        }
        else
        {
            return lrRotation(head);
        }
    }
    if(bf < -1)
    {
        if(balanceFactor(head->right) <= 0)
        {
            return llRotation(head->right);
        }
        else
        {
            return llRotation(head->right);
        }
    }
    return head;
}

int main()
{
    node*head = new node(1);
    head->left = new node(-1);
    head = insertNode(head, -2);
}