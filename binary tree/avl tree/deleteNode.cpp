#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

node* deleteNode(node *head, int key)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->val < key)
    {
        head->right = deleteNode(head->right, key);
    }
    else if(head->val > key)
    {
        head->left = deleteNode(head->left, key);
    }
    else
    {
        if(head->left == NULL && head->right == NULL)
        {
            free(head);
            return NULL;
        }
        else if(head->left == NULL)
        {
            node*temp = head->right;
            free(head);
            return temp;
        }
        else if(head->right == NULL)
        {
            node*temp = head->left;
            free(head);
            return head;
        }
        else
        {
            node*replacer = minNodeRight(head->right);
            head->val = replacer->val;
            head->right = deleteNode(head->right, replacer->val);
        }
    }
    if(head == NULL)
    {
        return head;
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
            return llRotation(head);
        }
        else
        {
            return rlRotation(head);
        }
    }
    return head;
}

int main()
{
    node*head = new node(5);
    head->left = new node(2);
    head->right = new node(7);
    head->left->left = new node(1);
    head->left->right = new node(3);
    head = deleteNode(head, 2);
    levelOrder(head);
}