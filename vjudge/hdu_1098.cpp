#include <iostream>
using namespace std;
int main()
{
    int k, a;
    while (cin >> k)
    {
        for (a = 0; a < 66; a++)
        {
            if ((k * a + 18) % 65 == 0)
            {
                cout << a << endl;
                break;
            }
        }
        if (a == 66)
            cout << "no" << endl;
    }
    return 0;
}