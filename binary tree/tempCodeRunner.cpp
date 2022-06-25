#include<bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

void flip(node *root)
{
    if(root != NULL)
    {
        node*temp = root->left;
        root->left = root->right;
        root->right = temp;
        flip(root->left);
        flip(root->right);
    }
    return;
}

bool isIdentical(node *a, node *b)
{
    if(a == NULL && b == NULL)
    {
        return true;
    }
    if(a != NULL || b != NULL)
    {
        return false;
    }
    if(a->val != b->val)
    {
        return false;
    }
    else
    {
        return true && isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    }
}

bool isSymmetric(node *head)
{
    if(head == NULL)
    {
        return false;
    }
    flip(head->right);
    return isIdentical(head->left, head->right);
}

int main()
{
    node *head = new node(1);
    head->left = new node(2);
    head->right = new node(2);
    head->left->left = new node(3);
    head->right->right = new node(3);
    cout << isSymmetric(head);
}


