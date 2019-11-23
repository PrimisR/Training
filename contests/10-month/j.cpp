/**
 * 求因子，如果因子的因子中包含已经计算过的其他因子，如果成功，则不必再次计算
 * substr用法
 * */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool visited[30000001];

int main()
{
    ios::sync_with_stdio(false);
    string str;
    while(cin>>str) {
        int len=str.length();
        int sqrt_len=sqrt(len);
        for(int i=1;i<=len;i++) {visited[i]=false;}
        int total=0;
        vector<int> factor;
        for(int i=1;i<=sqrt_len;i++)
        {
            if(len%i) continue;
            factor.push_back(i);
            factor.push_back(len/i);
        }
        if(sqrt_len*sqrt_len==len) factor.pop_back();
        for(int i=0;i<factor.size();i++)
        {
            int fa=factor[i];
            if(visited[fa]) {
                total+=fa;
                continue;
            }
            string substr=str.substr(0,fa);
            bool fail=false;
            for(int j=2;j<=len/fa;j++)
            {
                string cmpstr=str.substr(fa*(j-1),fa);
                if(substr!=cmpstr) {
                    fail=true;
                    break;
                }
            }
            if(!fail) {
                total+=fa;
                for(int i=1;i*fa<=len;i++) {
                    visited[i*fa]=true;
                }
            }
        }
        cout<<total<<endl;
    }
}