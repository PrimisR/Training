#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char m[256];

bool eql(char a, char b)
{
    return (a == b || m[a] == b || m[b] == a);
}

bool check(string str)
{
    int len = str.length();
    for (int i = 0; i <= (len / 2 - 1); i++)
    {
        if (!eql(str[i], str[len - i - 1]))
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    int CASE = 0;
    while (T--)
    {
        for (int i = 0; i < 256; i++)
            m[i] = 0;
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            char a, b;
            cin >> a >> b;
            m[a] = b;
            m[b] = a;
        }
        int s;
        cin >> s;
        string str;
        cout << "Test case #" << ++CASE << ":" << endl;
        for (int i = 1; i <= s; i++)
        {
            cin >> str;
            cout << str << " " << ((check(str)) ? "YES" : "NO") << endl;
        }
        cout << endl;
    }
    return 0;
}