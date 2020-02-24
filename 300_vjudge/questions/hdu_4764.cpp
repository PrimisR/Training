#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)==2&&(n||k))
    {
           if((n-1)%(k+1)) printf("Tang\n");
           else  printf("Jiang\n");
 
    }
    return 0;
}