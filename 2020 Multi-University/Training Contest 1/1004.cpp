#include <cstdio>
#include <iostream>

using namespace std;

const long long mod = 998244353;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        long long ans;
        if(n == 1) {
            ans = 26;
        }
        else if(n == 2) {
            ans = 676;
        }
        else if(n == 3) {
            ans = 17576;
        }
        else {
            ans = 15600;
        }
        cout << ans << endl;
    }
    return 0;
}