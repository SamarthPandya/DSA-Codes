#include <bits/stdc++.h>
#include "treeUtility.h"

using namespace std;


int search(vector<int>arr, int start, int end, int key)
{
    for(int i = start; i <= end; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
}

node *fromPreOrder(vector<int>inorder, vector<int>preorder, int inStart, int inEnd)
{
    static int preIndex = 0;
    if(inStart > inEnd)
    {
        return NULL;
    }
    node *head = new node(preorder[preIndex++]);
    if(inStart == inEnd)
    {
        return head;
    }
    int ind = search(inorder, inStart, inEnd, head->val);
    head->left = fromPreOrder(inorder, preorder, inStart, ind - 1);
    head->right = fromPreOrder(inorder, preorder, ind + 1, inEnd);
    return head;
}

node* fromPostOrder(vector<int>in, vector<int>post, int s, int e, int *pi)
{
    if (s > e)
    {
        return NULL;
    }
    node *head = new node(post[*pi]);
    (*pi)--;
    if(s == e)
    {
        return head;
    }
    int i = search(in, s, e, head->val);
    head->right = fromPostOrder(in, post, i + 1, e, pi);
    head->left = fromPostOrder(in, post, s, i - 1, pi);
    return head; 
}

int main()
{
    vector<int>ino = {4, 10, 2, 5, 1, 11, 9, 7, 3, 8}, p = {10, 4, 5, 2, 11, 9, 7, 8, 3, 1};
    int l = 9;
    node *head = fromPostOrder(ino, p, 0, 9, &l);
}