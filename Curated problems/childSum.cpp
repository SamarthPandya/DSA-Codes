#include<bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

void util(node* head)
{
    if (head != NULL)
    {
        if (head->left == NULL && head->right == NULL)
        {
            return;
        }
        int a, b, c;
        a = (head->left != NULL) ? head->left->val : 0;
        b = (head->right != NULL) ? head->right->val : 0;
        c = head->val;
        head->val = a + b + c;
        if (b != 0)
        {
            head->right->val = b + c;
        }
        else
        {
            head->left->val = a + c;
        }
        //cout << "done for " << c << '\n';
    }
}

void func(node* head)
{
    if (head != NULL)
    {
        util(head);
        func(head->left);
        func(head->right);
    }
}



int main()
{
    node* head = new node(5);
    head->left = new node(1);
    head->right = new node(2);
    head->right->left = new node(1);
    head->right->right = new node(1);
    func(head);
    levelOrder(head);
}