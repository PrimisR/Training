/**
 * 字典序搜索:dfs
 * 不符合的序列加上新的字符依然一定不符合
 * 符合的序列部分不需要检查，只需要检查新的字符带来的影响即可
 * */
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string str;
string answer;
int n,L;
int total = 0;

bool check(char new_char) {
    int max_len = (str.length()+1)/2;
    for(int len=1;len<=max_len;len++) {
        string pre = str.substr(str.length()-(len*2)+1,len);
        string post = str.substr(str.length()-len+1,len-1);
        post = post + new_char;
        if(pre == post) return false;
    }
    return true;
}

void dfs() {
    if(total == n) return;
    for(char i='A';i<'A'+L;i++) {
        if(total == n) break;
        if(check(i)) {
            str = str + i;
            total++;
            answer = str;
            // cout << str << endl;
            dfs();
            str = str.substr(0,str.length()-1);
        }
    }
}

void print_answer() {
    for(int i=0;i<answer.length();i++) { //注意行末空格
        if(!(i%4) && (i%64) && (i != answer.length()-1)) cout<<" ";
        else if(i == 64 && answer.length() > 64) cout<<endl;
        cout<<answer[i];
    }
    cout<<endl;
    cout<<answer.length()<<endl;
}

int main()
{
    while(cin>>n>>L && n && L) {
        total = 0;
        str = "";
        dfs();
        print_answer();
    }
    return 0;
}
