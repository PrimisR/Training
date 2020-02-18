#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int mm[100];
int main()
{
    int n;
    int m = 0;
    while (cin >> n && n >= 0)
    {
        int s = 0;
        m++;
        while (n--)
        {
            int a;
            cin >> a;
            s += a;
        }
        cout << "Sum of #" << m << " is ";
        cout << s << endl;
    }
    return 0;
}