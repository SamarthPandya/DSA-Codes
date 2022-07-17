#include<bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

/*node* rrRotation(node *head)
{
    node*a = head, *b = a->left, *c = a->left->left;
    node*temp = b->right;
    a->left = NULL;
    b->right = a;
    a->left = temp;
    return b;
}

node* llRotation(node*head)
{
    node*a = head, *b = a->right, *c = b->right;
    node*temp = b->left;
    a->right = NULL;
    b->left = a;
    a->right = temp;
    return b; 
}

node* lrRotation(node *head)
{
    node*a = head;
    node*b = head->left;
    node*c = head->left->right;
    node*temp1 = c->left;
    node*temp2 = c->right;
    c->left = b;
    c->right = a;
    b->right = temp1;
    a->left = temp2;
    return c;
}

node *rlRotation(node*head)
{
    node* a = head;
    node *b = head->right;
    node *c = b->left;
    node *temp1 = c->left;
    node *temp2 = c->right;
    c->left = a;
    c->right = b;
    a->right = temp1;
    b->left = temp2;
    return c;
}

int balFac(node *head)
{
    return height(head->left) - height(head->right);
}

Node*bInsert(node *head, int key)
{
    if(head == NULL)
    {
        return new node(key);
    }
    else if(head->val < key)
    {
        head->right = bInsert(head->right, key);
    }
    else
    {
        head->left = bInsert(head->left, key);
    }
    int bf = height(head->left) - height(head->right);
    
}

node* minNodeRight(node* head)
{
    node*temp = head;
    while(temp && temp->left)
    {
        temp = temp->left;
    }
    return temp;
}*/

node* deleteNode(node* head, int key)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->val < key)
    {
        head->right =  deleteNode(head->right, key);
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
            node *temp = head->right;
            free(head);
            return temp;
        }
        else if(head->right == NULL)
        {
            node* temp = head->left;
            free(head);
            return temp;
        }
        else
        {
            node*k = minNodeRight(head->right);
            head->val = k->val;
            head->right = deleteNode(head->right, k->val);
        }
    }
    return head;
}

node *avlRem(node*head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->val < key)
    {
        head->right = avlRem(head->right, key);
    }
    else if (head->val > key)
    {
        head->left = avlRem(head->left, key);
    }
    else
    {
        if (head->left == NULL && head->right == NULL)
        {
            free(head);
            return NULL;
        }
        else if (head->left == NULL)
        {
            node* temp = head->right;
            free(head);
            return temp;
        }
        else if (head->right == NULL)
        {
            node* temp = head->left;
            free(head);
            return temp;
        }
        else
        {
            node* k = minNodeRight(head->right);
            head->val = k->val;
            head->right = avlRem(head->right, k->val);
        }
    }
    if(head == NULL)
    {
        return head;
    }
    int bf = balanceFactor(head);
    if(bf > 1)
    {
        if (balanceFactor(head->left) >= 0)
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
        if(balanceFactor(head->right )<= 0)
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

auto minCost(vector<int>cost)
{
    int l = cost.size();
    vector<int>cheapestToReach;
    cheapestToReach.assign(l, 0);
    set<int>steps;
    cheapestToReach[0] = 0;
    cheapestToReach[1] = cost[1];
    for(int i = 2; i < l; i++)
    {
        int path1Cost = cheapestToReach[i - 1] + cost[i];
        int path2Cost = cheapestToReach[i - 2] + cost[i];
        int outPut = min(path1Cost, path2Cost);
        cheapestToReach[i] = outPut;
        steps.insert((outPut == path1Cost) ? i - 1 : i - 2);
    }
    cout << '\n' << cheapestToReach[l - 1] << '\n';
    for(auto i = steps.begin(); i != steps.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << '\n';
    for(int i : cheapestToReach)
    {
        cout << i << ' ';
    }
}

int main()
{
    node* head = new node(5);
    head->left = new node(2);
    head->right = new node(7);
    head->left->left = new node(1);
    head->left->right = new node(3);
    head = avlRem(head, 2);
    levelOrder(head);
}