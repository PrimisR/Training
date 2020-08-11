/**
 * 裸题,求最长上升子序列
 * dp[i] = max(dp[j]+1, dp[i]) (j<i, a[j] < a[i])
 * 优化O(nlogn)
 * 5 2 3 1 4 6
 * 1 2 3 4 5
 * 1 3
 * */
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), a);
        if (it == v.end())
            v.push_back(a);
        else
            *it = a;
    }
    cout << v.size() << endl;
    return 0;
}