#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int cnt[26];
int series[2];


int main() {
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++) {
        cnt[str[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        if(cnt[i] == 0) continue;
        if(cnt[i] & 1) {
            series[1]++;
        }
        else {
            series[0]++;
        }
    }
    if(series[0] != 0 && series[1] == 0) {
        cout << 0 << endl;
    }
    else if(series[0] == 0 && series[1] != 0) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
    return 0;
}