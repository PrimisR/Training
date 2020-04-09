#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int m;
    cin >> m;
    getchar();
    map<string, string> mss;
    while (m--)
    {
        string f, s;
        cin >> f >> s >> s;
        mss[f] = s;
    }
    int n;
    cin>>n;
    while (n--)
    {
        int len;
        cin >> len;
        getchar();
        for (int i = 0; i < len; i++)
        {
            string str;
            cin >> str;
            cout << mss[str];
            if (i != len - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
}