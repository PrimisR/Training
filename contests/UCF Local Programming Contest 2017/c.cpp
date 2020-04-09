#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    int T, len, cur, next;
    cin >> T;
    while (T--)
    {
        cin >> n >> len;
        long long res = 0;
        cin >> cur;
        for (int i = 0; i < len - 1; i++)
        {
            cin >> next;
            int diff = next - cur - 1;
            if (diff < 0)
                diff += n;
            res += min((long long)diff, n - diff);
            cur = next;
        }
        cout << res << endl;
    }
}
