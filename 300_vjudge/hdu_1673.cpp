#include <cstdio>
#include <algorithm>
#define maxn 30
using namespace std;
int a[maxn];
int main()
{
   int n;
   scanf("%d",&n);
   while(n--)
   {
       int x;
       scanf("%d",&x);
           for(int i=0;i<x;i++)
               scanf("%d",&a[i]);
        sort(a,a+x);
        int min=(a[x-1]-a[0])*2;
        printf("%d\n",min);
   }
   return 0;
}