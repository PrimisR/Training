#include <cstdio>
#include <iostream>

using namespace std;

int charge(int n, int a, int b)
{
    if (n <= 1000)
    {
        return n * a;
    }
    else
    {
        return 1000 * a + (n - 1000) * b;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << x << " " << charge(x, a, b) << endl;
    }
    return 0;
}