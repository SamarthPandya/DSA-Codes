#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

node* fromPreOrder(vector<int>pre)
{
    stack<node*>st;
    if(pre.size() == 0)
    {
        return NULL;
    }
    node*root = new node(pre[0]);
    node* p = root;
    for(int i = 1; i < pre.size(); i++)
    {
        int curr = pre[i];
        if(curr < p->val)
        {
            node*temp = new node(pre[i]);
            p->left = temp;
            st.push(p);
            p = p->left;
        }
        else
        {
            int prev = (st.size() == 0) ? INT_MAX : st.top()->val;
            if(curr < prev)
            {
                node* temp = new node(pre[i]);
                p->right = temp;
                p = p->right;
            }
            else
            {
                p = st.top();
                st.pop();
                node*temp = new node(pre[i]);
                p->right = temp;
                p = p->right;
            }
        }
    }
    return root;
}

void revU(vector<long long>& arr, int start, int end)
{
    int i = start, j = end;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
void reverseInGroups(vector<long long>& arr, int n, int k) {
    int left = 0;
    int right = ((left + k - 1) < n) ? left + k - 1 : n - 1;
    cout << left << ' ' << right << '\n';
    while (right < n - 1)
    {
        revU(arr, left, right);
        left = right + 1;
        right = ((left + k - 1) < n) ? left + k - 1 : n - 1;
    }
    revU(arr, left, n - 1);
}

int main()
{
    vector<long long>pre = {80, 60, 58, 65, 78, 100, 96, 101};
    reverseInGroups(pre, 8, 3);
    for(int i : pre)
    {
        cout << i << ' ';
    }
}