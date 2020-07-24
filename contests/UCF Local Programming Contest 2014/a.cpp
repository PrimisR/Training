#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

bool v(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
    int n;
    cin >> n;
    for (int loop = 1; loop <= n; loop++)
    {
        string str;
        cin >> str;
        int vc = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (v(str[i]))
                vc++;
        }
        cout << str << endl;
        cout << (vc > str.length() - vc) << endl;
    }
}