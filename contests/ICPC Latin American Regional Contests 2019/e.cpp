#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

string str;
int n;

int main()
{
    cin >> str >> n;
    int len = str.length();
    long long ans = n * (long long)len;
    int pos = -1;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'E')
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        int cnt = 0;
        for(int i=0;i<len-1;i++) {
            pos = (pos+1)%len;
            if(str[pos] == 'P') cnt++;
            else {
                if(cnt >= n) ans -= (2*cnt-n+1) * (long long)n / 2;
                else ans -= (cnt+1) * (long long)cnt / 2;
                cnt = 0;
            }
        }
        if(cnt >= n) ans -= (2*cnt-n+1) * (long long)n / 2;
        else ans -= (cnt+1) * (long long)cnt / 2;
        cout << ans << endl;
    }
}