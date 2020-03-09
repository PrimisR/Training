#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int n, m;
        cin >> n >> m;
        if (n % (m + 1))
        {
            cout << "first" << endl;
        }
        else
        {
            cout << "second" << endl;
        }
    }
}