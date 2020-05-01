#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;

int to_int(string str) {
    if(str == "") return 1;
    int out = 0;
    for(int i=0;i<str.length();i++) {
        out *= 10;
        out += str[i] - '0';
    }
    return out;
}

int main() {
    string in,out; int n;
    cin>>in>>n>>out;
    int cnt_in[26] = {};
    int cnt_out[26] = {};
    int ans[26] = {};
    char cur_c = in[0];
    string cur_num = "";
    for(int i=1;i<in.length();i++) {
        if(in[i] >= 'A' && in[i] <= 'Z') {
            cnt_in[cur_c-'A'] += to_int(cur_num);
            cur_c = in[i];
            cur_num = "";
        }
        else {
            cur_num = cur_num + in[i];
        }
    }
    cnt_in[cur_c-'A'] += to_int(cur_num);
    cur_c = out[0];
    cur_num = "";
    for(int i=1;i<out.length();i++) {
        if(out[i] >= 'A' && out[i] <= 'Z') {
            cnt_out[cur_c-'A'] += to_int(cur_num);
            cur_c = out[i];
            cur_num = "";
        }
        else {
            cur_num = cur_num + out[i];
        }
    }
    cnt_out[cur_c-'A'] += to_int(cur_num);
    int min_v = inf;
    for(int i=0;i<26;i++) {
        if(cnt_out[i] == 0) continue;
        ans[i] = cnt_in[i] * n / cnt_out[i];
        min_v = min(min_v,ans[i]);
    }
    cout << min_v << endl;
    return 0;
}