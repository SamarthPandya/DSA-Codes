#include<bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

void util(node *head, int&ans)
{
    if(head != NULL)
    {
        int temp = height(head->left) + height(head->right) + 2;
        if (temp > ans)
        {
            ans = temp;
        }
        util(head->left, ans);
        util(head->right, ans);
    }
}

int diameter2(node*head)
{
    int ans;
    util(head, ans);
    return ans;
}

int main()
{
    node* head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    head->left->left = new node(4);
    head->left->right = new node(5);
    head->left->right->left = new node(6);
    head->right->right = new node(7);
    head->right->right->left = new node(8);
    head->right->right->right = new node(9);
}
