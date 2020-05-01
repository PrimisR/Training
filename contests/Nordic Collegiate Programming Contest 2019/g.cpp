#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100];
const int inf = 0x3f3f3f3f;

int main()
{
    cin >> n;
    int minv = inf;
    int mini = inf;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n - 2; i++)
    {
        int tmax = max(arr[i], arr[i + 2]);
        if (tmax < minv)
        {
            minv = tmax;
            mini = i;
        }
    }
    cout << mini << " " << minv << endl;
    return 0;
}