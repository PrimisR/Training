#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int main()
{
    int n;
    int a[N];
    int b[N];
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(b,b+n,a[i]) - b;
        if(pos == 0) {
            ans = max(ans,b[0]-a[i]);
        }
        else if(pos == n) {
            ans = max(ans,a[i]-b[n-1]);
        }
        else {
            ans = max(ans,min(b[pos]-a[i],a[i]-b[pos-1]));
        }
    }
    cout << ans << endl;
    return 0;
}