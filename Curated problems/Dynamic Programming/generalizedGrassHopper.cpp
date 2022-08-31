/*
Given
* 1) n: The length of cost matrix.
* 2) k: Maximum permissible jump length.
* 3) C[n]: Cost matrix. C[i] = cost of occupying the ith position.

todo: Find the cost minimizing path form 0 to n - 1.

There is only one state parameter i (current position).
Let d[i] = Minimum Cost of reaching ith position.

* Idea: d[n] = min{d[n - i] + c[n] | 1 <= i <= min{n, k}} for n > 1
*       d[0] = 0
*       d[1] = c[1] 
*/

#include <bits/stdc++.h>

using namespace std;

int minCost(vector<int>cost, int n, int k)
{
    vector<int>d;
    d.assign(n, 0);
    d[1] = cost[1];
    for(int j = 2; j < n; j++)
    {
        int cheapest = d[j - 1] + cost[j];
        int i = 2;
        while (i <= k && j - i >= 0)
        {
            int temp = d[j - i] + cost[j];
            if(temp < cheapest)
            {
                cheapest = temp;
            }
            i = i + 1;
        }
        d[j] = cheapest;
    }
    for(int i : d)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return d[n-1];
}

int main()
{
    vector<int>c = {0, 3, 2, 4, 2, 3, 1, 4, 0};
    cout << minCost(c, 9, 6);
}