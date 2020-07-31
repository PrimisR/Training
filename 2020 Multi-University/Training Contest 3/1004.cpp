/**
 * 
 * */
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        int n, p;
        cin >> n >> p;
        set<long long> s;
        s.insert(0);
        int ans = 0;
        long long tot = 0;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            tot = (a + tot) % p;
            int old_sz = s.size();
            s.insert(tot);
            if (s.size() == old_sz)
            {
                ans++;
                tot = 0;
                s.clear();
                s.insert(0);
            }
        }
        cout << ans << endl;
    }
    return 0;
}