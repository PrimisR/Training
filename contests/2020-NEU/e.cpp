#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000005;

int diff(int a,int b) {
    a %= 7;
    b %= 7;
    if(a > b) swap(a,b);
    return min(b-a,a+7-b);
}

int a[maxn];
int b[maxn];
int d[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    for (int loop = 1; loop <= T; loop++)
    {
        int n,t;
        scanf("%d %d",&n,&t);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        for(int i=0;i<n;i++) d[i] = diff(a[i],b[i]);
        int max_len = 0;
        int l=0;
        for(int r=0;r<n-1;r++) {
            if(d[r] > t) {
                max_len = max(max_len,r-l);
                l = r+1;
            }
        }
        max_len = max(max_len,n-l);
        printf("%d\n",max_len);
        // for(int i=0;i<n;i++) printf("%d ",d[i]);
        // printf("\n");
    }
    return 0;
}