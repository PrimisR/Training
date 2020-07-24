#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    char op1, op2;
    cin >> a >> op1 >> b >> op2 >> c;
    if (a + b == c)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}