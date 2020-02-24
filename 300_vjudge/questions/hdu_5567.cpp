///1085422276
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

typedef long long ll;
#define mem(a) memset(a,0,sizeof(a))
#define pb push_back

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';ch=getchar();
    }return x*f;
}
//****************************************
const int N=100000+350;
#define maxn 100000+5

int main()
{
    int n,b,c,a[N];
    while(scanf("%d%d%d",&n,&b,&c)!=EOF) {
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }int ans=0;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(abs(a[i]-a[j])%b==c) {
                    ans++;
                }
            }
        }cout<<ans<<endl;
    }
    return 0;
}