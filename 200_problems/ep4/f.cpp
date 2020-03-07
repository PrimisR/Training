#include <iostream>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

bool is_surprising(const string str)
{
    int len = str.length();
    for (int d = 0; d <= len - 2; d++)
    {
        set<int> s;
        for (int i = 0; i <= len - d - 1; i++)
        {
            int code = (str[i] - 'A') * 100 + (str[i + d + 1] - 'A');
            int old_size = s.size();
            s.insert(code);
            int new_size = s.size();
            if (new_size != old_size + 1)
                return false;
        }
    }
    return true;
}

int main()
{
    string str;
    while (cin >> str && str != "*")
    {
        if (is_surprising(str))
            cout << str << " is surprising." << endl;
        else
            cout << str << " is NOT surprising." << endl;
    }
}