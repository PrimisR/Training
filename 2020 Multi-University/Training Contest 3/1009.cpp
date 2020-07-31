#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const string N = "No solution!";

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        bool flag = true;
        vector<int> apos;
        string s;
        cin >> s;
        int totl = 0, totr = 0, tota = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                totl++;
            else if (s[i] == ')')
                totr++;
            else
            {
                tota++;
                apos.push_back(i);
            }
        }
        int lftl = 0, lfta = 0;
        int lptr = 0; // apos.size()?
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                lftl++;
            else if (s[i] == '*')
                lfta++;
            else
            {
                if (lftl == 0)
                {
                    if (lfta == 0)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        if (lptr == apos.size())
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            lfta--;
                            s[apos[lptr++]] = '(';
                        }
                    }
                }
                else
                    lftl--;
            }
        }
        int rgtr = 0, rgta = 0;
        int rptr = apos.size() - 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                rgtr++;
            else if (s[i] == '*')
                rgta++;
            else
            {
                if (rgtr == 0)
                {
                    if (rgta == 0)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        if (rptr < lptr)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            rgta--;
                            s[apos[rptr--]] = ')';
                        }
                    }
                }
                else
                    rgtr--;
            }
        }
        if (!flag)
            cout << N << endl;
        else
        {
            string ans = "";
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '*')
                    continue;
                else
                    ans.push_back(s[i]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}