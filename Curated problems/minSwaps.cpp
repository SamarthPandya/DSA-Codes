// https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

/*
todo: Find the min number of adjacent swaps to reach the kth consecutive permutation
* IDEA: kth wonderful number = kth smallest permutation
  ALGORITHM
* Step 1: Given nums, find its kth consecutive permutation, 'kthPermutation'
* Step 2: Find the min No. of adj. swaps to reach from nums1 to kthPermutation
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // function to find the min adj. swaps to go from a to b
    int minSwaps(string &a, string &b)
    {
        int i = 0, j, k, ans = 0;
        while(a != b) // while both strings do not become equal
        {
            while(a[i] == b[i])
            {
                i++;
            } // finding the first index at which strings are unequal.
            char key = a[i];
            j = i + 1;
            while(j < b.size() && b[j] != key)
            {
                j++;
            } // finding the key in b
            while(j > i)
            {
                swap(b[j], b[j - 1]);
                j--;
                ans++;
            } // bringing key to its correct position in b.
            i++;
        }
        return ans;
    }
    int getMinSwaps(string num, int k) {
        string kthPermutation = num;
        while(k != 0)
        {
            next_permutation(kthPermutation.begin(), kthPermutation.end());
            k--;
        } // finding kth consecutive permutation.
        return minSwaps(kthPermutation, num); // implementing step 2.
    }
};

// driver code
int main()
{
    string a = "5489355142";
    Solution s;
    cout << s.getMinSwaps(a, 4);
}