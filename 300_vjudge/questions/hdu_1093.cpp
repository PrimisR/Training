#include <iostream>
using namespace std;
int main()
{
    int n, m, a, sum = 0;
    while (cin >> n)
    {
        while (n--)
        {
            cin >> m;
            sum = 0;
            while (m--)
            {
                cin >> a;
                sum = sum + a;
            }
            cout << sum << endl;
        }
    }

    return 0;
}