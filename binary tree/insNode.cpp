#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

node*insert_node(node *head, int key)
{
    if(head == NULL)
    {
        node* newNode = new node(key);
        return newNode;
    }
    if(head->val < key)
    {
        head->right = insert_node(head->right, key);
    }
    else
    {
        head->left = insert_node(head->left, key);
    }
    return head;
}

int main()
{
    node*head = new node(5);
    head->left = new node(3);
    head->right = new node(7);
    preOrder(insert_node(head, 17));
}
