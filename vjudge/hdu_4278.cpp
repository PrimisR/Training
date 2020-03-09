#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define N 5005
#define ll long long

using namespace std;

int a[]= {0,1,2,0,3,4,5,6,0,7,0};
ll k;

int main() {
    //freopen("test.in","r",stdin);
    while(~scanf("%I64d",&k)&&k) {
        int num[10];
        int l=0;
        ll kk=k;
        while(k) {
            num[l++]=k%10;
            k/=10;
        }
        ll p=1;
        ll ans=0;
        for(int i=0; i<l; i++) {
            ans+=a[num[i]]*p;
            p*=8;
        }
        printf("%I64d: %I64d\n",kk,ans);
    }
    return 0;
}