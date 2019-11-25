/**
 * 利用前缀和的思想自然完成天数的乘积
 * 而且结果前后也有关系
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int cmp(int a,int b) {
    return a < b;
}

int sweet[200005];
long long prefix_sum[200005];
long long result[200005];

int main()
{
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>sweet[i];
    }
    sort(sweet+1,sweet+n+1,cmp);
    prefix_sum[1] = sweet[1];
    for(int i=2;i<=n;i++) {
        prefix_sum[i] = prefix_sum[i-1] + sweet[i];
    }
    for(int i=1;i<=m;i++) {
        result[i] = prefix_sum[i];
    }
    for(int i=m+1;i<=n;i++) {
        result[i] = result[i-m] + prefix_sum[i];
    }
    for(int i=1;i<=n;i++) {
        cout<<result[i];
        if(i != n) cout<<" ";
        else cout<<endl;
    }
    return 0;
}