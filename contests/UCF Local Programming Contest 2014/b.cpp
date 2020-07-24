#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int loop = 1; loop <= n; loop++)
    {
        int g, p;
        cin >> g >> p;
        int w[1000] = {}, t[1000] = {};
        int sz = 0;
        int sw = p / 3;
        if (sw < 0)
            break;
        for (int i = sw; i >= 0; i--)
        {
            int st = p - i * 3;
            if (i + st > g)
                break;
            w[sz] = i;
            t[sz] = st;
            sz++;
        }
        cout << "Team #" << loop << endl;
        cout << "Games: " << g << endl;
        cout << "Points: " << p << endl;
        cout << "Possible records:" << endl;
        for (int i = 0; i < sz; i++)
        {
            cout << w[i] << "-" << t[i] << "-" << g-w[i]-t[i] << endl;
        }
        cout << endl;
    }
}