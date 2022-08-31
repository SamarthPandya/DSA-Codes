#include <iostream>
#include <bits/stdc++.h>
#include "C:\Users\HP 14 DR2016TU 11i5\Desktop\HOME\Serious\binary tree\treeUtility.h"

using namespace std;

int filler(vector<int>a, vector<int>b, int i, int j, vector<vector<int>>&m)
{
    if(m[i][j] >= 0)
    {
        return m[i][j];
    }
    else
    {
        if(a[i - 1] == b[j - 1])
        {
            int q = 1 + filler(a, b, i - 1, j - 1, m);
        }
        else
        {
            if()
        }
    } 
}