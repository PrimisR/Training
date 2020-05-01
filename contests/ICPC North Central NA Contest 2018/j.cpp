#include <iostream>
using namespace std;
bool check(int x, int k)
{
    int s[100006], ans = 0;
    while (x)
    {
        s[ans++] = x % k;
        x /= k;
    }
    for (int i = 0; i <= ans / 2; i++)
    {
        if (s[i] != s[ans - 1 - i])
            return false;
    }
    return true;
}
int main()
{
    int x, y, k;
    cin >> x >> y >> k;
    int sum = 0;
    for (int i = x; i <= y; i++)
    {
        int tk = 2;
        for (; tk <= k; tk++)
        {
            if (check(i, tk) == 0)
            {
                break;
            }
        }
        if (tk == k + 1)
            sum++;
    }
    cout << sum << endl;
    return 0;
}