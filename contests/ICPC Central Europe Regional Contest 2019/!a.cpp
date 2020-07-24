#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> z_fun(string s)
{
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin>>n;
    cin>>s;
    string rs = s;
    reverse(rs.begin(), rs.end());
    rs += s;
    vector<int> z = z_fun(rs);
    int res = rs.size();
    for (int i = n; i < (int)rs.size(); ++i) {
        if (i + z[i] == 2 * n)
            res = min(res, n - z[i]);
    }
    cout << res << endl;
    return 0;
}