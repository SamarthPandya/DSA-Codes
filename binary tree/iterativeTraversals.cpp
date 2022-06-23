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



int main()
{
    node *head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    head->left->left = new node(4);
    vector<int>g = iterativeInorder(head);
    for(int i : g)
    {
        cout << i << ' ';
    }
}
