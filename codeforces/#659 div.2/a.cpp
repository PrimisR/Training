#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char next(char ch)
{
    return (char)((ch - 'a' + 1) % 26 + 'a');
}

int main()
{
    int t;
    cin >> t;
    for (int loop = 1; loop <= t; loop++)
    {
        int a[200];
        int n;
        cin >> n;
        vector<string> ans;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        string cur = "";
        for (int i = 0; i < 110; i++)
        {
            cur.push_back('a');
        }
        ans.push_back(cur);
        for (int i = 1; i < n + 1; i++)
        {
            cur = (cur.substr(0, a[i]) + next(cur[a[i]]));
            for (int j = 0; j < 109 - a[i]; j++)
            {
                cur.push_back('a');
            }
            ans.push_back(cur);
        }
        for (int i = 0; i < n + 1; i++)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}