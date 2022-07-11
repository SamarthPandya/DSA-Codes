#include <bits/stdc++.h>
#include "treeUtility.h"

using namespace std;

vector<int>iterativeInorder(node *head)
{
    vector<int>ans;
    stack<node*>st;
    st.push(head);
    node* curr = head->left;
    while(!(st.empty() && curr == NULL))
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }
    return ans;
}

vector<int>iterativePreorder(node *head)
{
    vector<int>ans;
    node *curr = head;
    node *temp;
    stack<node *>st;
    while(!(st.empty() == true && curr == NULL))
    {
        while(curr != NULL)
        {
            ans.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        }
        temp = st.top();
        st.pop();
        curr = temp->right;
    }
    return ans;
}

vector<int> iterativePostorder(node *head)
{
    stack<node*>st1;
    stack<node*>st2;
    st1.push(head);
    vector<int>ans;
    while(!st1.empty())
    {
        node*temp = st1.top();
        st2.push(temp);
        st1.pop();
        if(temp->left != NULL)
        {
            st1.push(temp->left);
        }
        if(temp->right != NULL)
        {
            st1.push(temp->right);
        }
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}



int main()
{
    node *head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    head->left->left = new node(4);
    head->left->right = new node(5);
    head->left->right->left = new node(6);
    head->right->right = new node(7);
    head->right->right->left = new node(8);
    head->right->right->right = new node(9);
    vector<int>g = iterativePostorder(head);
    for(int i : g)
    {
        cout << i << ' ';
    }
}
