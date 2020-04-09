#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

bool is_sim(char a, char b)
{
    int c = abs(a - b);
    return c == 9 || c == 8 || c == 10 || c == 1;
}

int situation(string &s1, string &s2)
{
    bool similar = false;
    if (s1.length() != s2.length())
        return 3;
    for (int i = 0; i < s1.length(); i++)
    {
        bool res = is_sim(s1[i], s2[i]);
        if (s1[i] != s2[i] && !res)
        {
            return 3;
        }
        else if (res)
        {
            similar = true;
        }
    }
    if (similar)
        return 2;
    return 1;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << situation(s1, s2) << endl;
    }
}