/**
 * 思路：枚举删除的人数，取最大的平均值
 * 注意min的函数要转换成long long入参而不是用long long接
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define long long long
 
using namespace std;
 
int a[1000000];
vector<double> v;
 
int main()
{
    int n,k,m;
    while(cin>>n>>k>>m)
    {
        v.clear();
        long op=min((long)n*(long)k,(long)m);
        long total=0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            total+=a[i];
        }
        sort(a,a+n);
        v.push_back((double)(total+op)/(double)n);
        for(int del=1;del<=m&&del<n;del++) {
            total-=a[del-1];
            op=min((long)(n-del)*(long)k,(long)(m-del));
            v.push_back((double)(total+op)/(double)(n-del));
        }
        sort(v.begin(),v.end());
        printf("%.12lf\n",v[v.size()-1]);
    }
}