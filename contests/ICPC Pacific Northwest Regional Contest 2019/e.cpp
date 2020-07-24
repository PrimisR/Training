#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const long long mod = 11092019;

int main()
{
    long long cnt[26] = {};
    string str;
    long long ans = 1;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        cnt[str[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        ans = ans * (cnt[i]+1) % mod;
    }
    cout << ans << endl;
}