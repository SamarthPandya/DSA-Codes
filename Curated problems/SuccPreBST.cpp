/*
todo: Find the successor and predecessor of the given key in BST
IDEA: 
*Inorder traversal of a bst is an increasing sequence.
*So do inorder traversal and keep updating the value.
*/

#include<bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"


void successorUtil(node *head, int key, int&v)
{
    if(head != NULL)
    {
        successorUtil(head->left, key, v);
        if(head->val > key && v > head->val)
        {
            v = head->val;
        }
        successorUtil(head->right, key, v);
    }
}

int successor(node *head, int key)
{
    int ans = INT_MAX;
    successorUtil(head, key, ans);
    return ans;
}

void predecessorUtil(node* head, int key, int& v)
{
    if (head != NULL)
    {
        predecessorUtil(head->left, key, v);
        if (head->val < key && v < head->val)
        {
            v = head->val;
        }
        predecessorUtil(head->right, key, v);
    }
}

int predecessor(node*head, int key)
{
    int ans = INT_MIN;
    predecessorUtil(head, key, ans);
    return ans;
}

int main()
{
    node *head = new node(2);
    head->left = new node(1);
    head->right = new node(3);
    cout << predecessor(head, 2);
}