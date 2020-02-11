/**
 * anagram: t 是 s 的字母重排，则 t 和 s 互为 anagram
 * reducible anagram: s 分段成多个子字符串 s1,s2,s3...(k>2)
 * 对于每一个si写出他的anagram再重组，得到 t 是 s 的 reducible anagram
 * irreducible anagram:
 * 那么如果存在一个 t 是 s 的 anagram，但是又不满足 reducible anagram 的条件
 * 那么 t 是 s 的 irreducible anagram
 * len = 1一定存在 irreducible anagram
 * 一个字符串不存在 irreducible anagram 的必要条件:
 * 1.这个区间包含一种字符构成的字符串，并且区间长度大于1
 * 2.
 * 求区间字符串字符种类
 * 给26个字母各自开一个前缀和数组
 * */
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAX_LEN = 200005;

int pre_sum[MAX_LEN][30];

int kinds(int l,int r) {
    int kinds = 0;
    for(int i='a'-'a';i<='z'-'a';i++) {
        if(pre_sum[r][i] - pre_sum[l-1][i] > 0) kinds++;
    }
    return kinds;
}

int main()
{
    string str; cin>>str;
    string answer;
    for(int i=0;i<str.length();i++) {
        int pos = i+1;
        int ch = str[i] - 'a';
        for(int j='a'-'a';j<='z'-'a';j++) {
            pre_sum[pos][j] = (j == ch)? pre_sum[pos-1][j]+1 : pre_sum[pos-1][j];
        }
    }
    // for(int i=1;i<=str.length();i++) {
    //     for(int j='a'-'a';j<='z'-'a';j++) {
    //         cout << pre_sum[i][j];
    //     }
    //     cout << endl;
    // }
    int query; cin>>query;
    while(query--) {
        int l,r; cin>>l>>r;
        if(l == r) {
            cout << "Yes" << endl;
            continue;
        }
        if(kinds(l,r) == 1) {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
        // cout << kinds(l,r) << endl;
    }
}