#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[105];
        int even = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            if ((arr[i] & 1) == 0)
                even = i;
        }
        if (even != -1)
        {
            cout << "1" << endl;
            cout << even << endl;
        }
        else if (n == 1)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << "2" << endl;
            cout << "1 2" << endl;
        }
    }
    return 0;
}