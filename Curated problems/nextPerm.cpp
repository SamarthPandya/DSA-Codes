// https://leetcode.com/problems/next-permutation/

/*
todo: Find the next permuation of a given array 'a'
  ALGORITHM
* Step 1: Find the last index pi such that a[pi] < a[pi + 1]
    ? If no such pi exists, return the reversed array
* Step 2: Find the last index t such that a[t] > a[pi]
* Step 3: swap(a[pi], a[t])
* Step 4: reverse a[pi + 1 : ]
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivot_index(vector<int>a)
    {
        int i, out = a.size() - 1;
        for (i = a.size() - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
            {
                out = i;
                break;
            }
        }
        return out;
    }
    void rev(vector<int>& a, int p)
    {
        vector<int>g;
        int i;
        for (i = a.size() - 1; i > p; i--)
        {
            g.push_back(a[i]);
        }
        for (i = p + 1; i < a.size(); i++)
        {
            a[i] = g[i - p - 1];
        }
    }
    void nextPermutation(vector<int>& nums) {
        int p = pivot_index(nums);
        if (p == nums.size() - 1)
        {
            rev(nums, -1);
        }
        else
        {
            int j, t;
            for (j = nums.size() - 1; j >= p + 1; j--)
            {
                if (nums[p] < nums[j])
                {
                    t = j;
                    break;
                }
            }
            swap(nums[t], nums[p]);
            rev(nums, p);
        }
    }
};

// driver function
int main()
{
    Solution s;
    vector<int>g = {1, 2, 4, 3};
    s.nextPermutation(g);
    for(int i : g)
    {
        cout << i << ' ';
    }
}