#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n, d;
string str;

const int K = 200005;

int cnt[K][26];

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> d;
        cin >> str;
        for(int i=0;i<d;i++) {
            for(int j=0;j<26;j++) {
                cnt[i][j] = 0;
            }
        }
        int k = n / d;
        for (int i = 0; i < str.length(); i++)
        {
            int p = i % d;
            if (p > d - 1 - p)
                p = d - 1 - p;
            cnt[p][str[i] - 'a']++;
        }
        int ans = 0;
        int upper = (d % 2 == 0) ? d / 2 : (d + 1) / 2;
        for (int i = 0; i < upper; i++)
        {
            int maxv = 0;
            for (int j = 0; j < 26; j++)
                maxv = max(cnt[i][j], maxv);
            //sort(cnt[i], cnt[i] + 26, cmp);
            int tot = (d % 2 == 1 && i == (d - 1) / 2) ? k : 2 * k;
            ans += (tot - maxv);
        }
        cout << ans << endl;
    }
}