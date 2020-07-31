#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long r = (n & 1) ? 0 : n / 2;
    vector<int> ans;
    if (k == r)
    {
        if (n & 1)
        {
            ans.push_back(n);
            for (int i = 1; i <= n / 2; i++)
            {
                ans.push_back(i);
                ans.push_back(n - i);
            }
        }
        else
        {
            ans.push_back(n);
            ans.push_back(n / 2);
            for (int i = 1; i < n / 2; i++)
            {
                ans.push_back(i);
                ans.push_back(n - i);
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i != ans.size() - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}