#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
  int n,a,b,k,i,sum;
  while(scanf("%d",&n)&&n!=-1)
  {
    sum=0;
    k=0;
    for(i=1;i<=n;i++)
    {
      scanf("%d%d",&a,&b);
      sum=sum+a*(b-k);
      k=b;
    }
    printf("%d miles\n",sum);
  }
  return 0;
}