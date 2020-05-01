#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int N = 1000005;

int main()
{
    int cnt[26]{};
    int kind = 0;
    string str;
    char ans[N];
    int len = 0;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        cnt[str[i] - 'a']++;
    }
    for(int i=0;i<26;i++) {
        if(cnt[i] == 0) continue;
        kind++;
        for(int j=len;j!=len+cnt[i];j++) {
            ans[j] = i+'a';
        }
        len += cnt[i];
    }
    if(kind == 1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for(int i=0;i<len;i++) {
            printf("%c",ans[i]);
        }
        cout << endl;
    }
    return 0;
}