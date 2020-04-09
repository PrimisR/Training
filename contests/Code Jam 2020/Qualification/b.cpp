#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 105;

int main()
{
    int T;
    cin >> T;
    int CASE = 0;
    while (T--)
    {
        string str;
        cin >> str;
        int len = str.length();
        int left[N]{};  // i前面放left[i]个左括号
        int right[N]{}; // i前面放right[i]个右括号
        int a[N]{};
        int b[N]{};
        for (int i = 1; i <= len; i++)
        {
            a[i] = str[i - 1] - '0';
            b[i] = a[i];
        }
        for (int i = 1; i <= len; i++)
        {
            int j;
            for (j = i + 1; j <= len; j++)
            {
                if (b[j] >= b[i])
                {
                    b[j] -= b[i];
                }
                else
                    break;
            }
            left[i] += b[i];
            right[j] += b[i];
        }
        cout << "Case #" << ++CASE << ": ";
        for (int i = 1; i <= len; i++)
        {
            int minx = min(left[i],right[i]);
            for (int j = 1; j <= left[i]-minx; j++)
            {
                cout << "(";
            }
            for (int j = 1; j <= right[i]-minx; j++)
            {
                cout << ")";
            }
            cout << a[i];
        }
        int minx = min(left[len+1],right[len+1]);
        for (int i = 1; i <= left[len + 1]-minx; i++)
        {
            cout << "(";
        }
        for (int i = 1; i <= right[len + 1]-minx; i++)
        {
            cout << ")";
        }
        cout << endl;
    }
    return 0;
}