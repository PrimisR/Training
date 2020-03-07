#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1100];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        for (int i = 1; i <= N; ++i)
            cin >> a[i];
        int num = 0;
        for (int i = 1; i <= N; ++i)
            if (a[i] > a[K])
                num++;
        cout << num << endl;
    }

    return 0;
}
