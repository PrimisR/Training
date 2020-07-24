#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long pw[64] = {};

void init()
{
    pw[0] = 1LL;
    for (int i = 1; i <= 63; i++)
    {
        pw[i] = pw[i - 1] << 1;
    }
}

int main()
{
    init();
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        long long k;
        cin >> k;
        vector<long long> ans;
        int ptr = upper_bound(pw, pw + 64, k + 1) - pw - 1;
        for (int i = 0; i < ptr; i++)
            ans.push_back(pw[i]);
        long long diff = k + 1 - pw[ptr];
        if (diff != 0)
            ans.push_back(diff);
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if(i != ans.size()-1) cout << " ";
            else cout << endl;
        }
    }
}