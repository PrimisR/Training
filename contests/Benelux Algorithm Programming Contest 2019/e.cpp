#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int total = 0;
    bool is_minus = false;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        int a = str[i] - '0';
        int post = (i == len - 1) ? 0 : str[i + 1] - '0';
        if (a > 5)
        {
            if (is_minus)
            {
                total += 9 - a;
            }
            else
            {
                is_minus = true;
                total++;
                total += 9 - a;
            }
            if (i == len - 1)
                total++;
        }
        else if (a == 5)
        {
            if (is_minus || post >= 5)
            {
                if (is_minus)
                {
                    total += 9 - a;
                }
                else
                {
                    is_minus = true;
                    total++;
                    total += 9 - a;
                }
                if (i == len - 1)
                    total++;
            }
            else
            {
                if (is_minus)
                {
                    is_minus = false;
                    total++;
                    total += a;
                }
                else
                {
                    total += a;
                }
            }
        }
        else if (a == 4)
        {
            if (is_minus && post >= 5)
            {
                if (is_minus)
                {
                    total += 9 - a;
                }
                else
                {
                    is_minus = true;
                    total++;
                    total += 9 - a;
                }
                if (i == len - 1)
                    total++;
            }
            else
            {
                if (is_minus)
                {
                    is_minus = false;
                    total++;
                    total += a;
                }
                else
                {
                    total += a;
                }
            }
        }
        else
        {
            if (is_minus)
            {
                is_minus = false;
                total++;
                total += a;
            }
            else
            {
                total += a;
            }
        }
    }
    std::cout << total << endl;
    //main();
    return 0;
}