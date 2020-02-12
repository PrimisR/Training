/**
 * anagram:t是s的字母重排，则t和s互为anagram
 * reducible anagram:s分段成多个子字符串s1,s2,s3...(k>2)
 * 对于每一个si写出他的anagram再重组，得到t是s的reducible anagram
 * irreducible anagram:
 * 那么如果存在一个t是s的anagram，但是又不满足reducible anagram的条件
 * 那么t是s的irreducible anagram
 * 也就是说，任意相同长度的前缀字符和(除去全部长度)都不相同
 * 讨论:
 * 1.(kinds=1)len=1:"Yes"
 * 2.kinds=1,len>=2:"No"
 * 3.考虑构造irreducible anagram
 * 1)如果左右两端str[l] != str[r],那么构造一个 str[r]...str[r],...,str[l]...str[l]的序列(中间可有可无)
 * 这样的话,任意从左到右区间的str[r]和str[l]数量一定不等，必然有irreducible anagram
 * 2)如果左右两端str[l] == str[r] == ch
 * 2.1)如果kinds>=3,那么除了ch以外，选定两个类似1)的方式构造,只不过有一些按情况有改动
 * 2.2)如果kinds==2,观察从左向右任意长度ch的前缀字符和,
 * 设ch总数为x,从第1到len-1位,s是1~x-1,t是0~x(两边不是ch),
 * 而且两者连续,必然有一个位置前缀和相等,所以无论怎样构造，都没有irreducible anagram
 * 
 * 整体思路是t的某一字母前缀和永远比s大，无论该字母是否用完
 * 
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
        if(str[l-1] != str[r-1]) {
            cout << "Yes" << endl;
            continue;
        }
        if(kinds(l,r) >= 3) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}