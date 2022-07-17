#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

node* minNodeRight(node* head)
{
    while (head && head->left)
    {
        head = head->left;
    }
    return head;
}

node *delete_node(node *head, int key)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->val > key)
    {
        head->left = delete_node(head->left, key);
    }
    else if(head->val < key)
    {
        head->right = delete_node(head->right, key);
    }
    else
    {
        if(head->left == NULL && head->right == NULL)
        {
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
            return temp;
        }
        else
        {
            node*replacer = minNodeRight(head->right);
            head->val = replacer->val;
            head->right = delete_node(head->right, replacer->val);
        }
    }
    return head;
}

int main()
{
    node* head = new node(5);
    head->left = new node(3);
    head->right = new node(7);
    levelOrder(delete_node(head, 5));
}