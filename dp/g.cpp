/**
 * 思想：贪心
 * 每当来一个导弹，就用高度最近的系统去拦截
 * 如果没有，就新开一个系统
 * */

/**
 * 贪心，动态规划思想：
 * 寻找最长不上升子串，不断删除
 * */

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

multiset<int> s;

int main()
{
    int n;
    while(cin>>n)
    {
        int num;
        cin>>num;
        s.insert(num);
        for(int i=1;i<n;i++)
        {
            cin>>num;
            if(num>(*(--s.end()))) s.insert(num);
            else {s.erase(*s.lower_bound(num)); s.insert(num);}
        }
        cout<<s.size()<<endl;
        s.clear();
    }
}