#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int tot = 0;
        if (a >= 10)
            tot++;
        if (b >= 10)
            tot++;
        if (c >= 10)
            tot++;
        string str;
        switch (tot)
        {
        case 0:
            str = "zilch";
            break;

        case 1:
            str = "double";
            break;

        case 2:
            str = "double-double";
            break;

        case 3:
            str = "triple-double";
            break;
        }
        cout << a << " " << b << " " << c << endl;
        cout << str << endl;
        cout << endl;
    }
    return 0;
}