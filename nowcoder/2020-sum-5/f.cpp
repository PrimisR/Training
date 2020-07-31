#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void output(long long d, long long maxd) // long long?
{
    long long s = ceil(50 * d * 1.0 / maxd * 1.0);
    cout << "+";
    for (int i = 1; i <= s; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|";
    for (int i = 1; i <= s; i++)
    {
        if (i == s && d == maxd)
        {
            cout << "*";
        }
        else
        {
            cout << " ";
        }
    }
    cout << "|" << d << endl;
    cout << "+";
    for (int i = 1; i <= s; i++)
        cout << "-";
    cout << "+";
}

int main()
{
    int n;
    cin >> n;
    long long d[200];
    long long maxd = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
       maxd = max(maxd,d[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(i) cout << endl;
        output(d[i], maxd);
    }
    return 0;
}
