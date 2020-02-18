#include<cstdio>
int main()
{
  //int a[5]={1,2,4,7,15};
  int a[5];
  a[0]=1;a[1]=2;a[2]=4;a[3]=7;a[4]=15;
  int num,i;
  while(scanf("%d",&num)!=EOF)
  {
    for(i=4;i>=0;i--)
    {
     // printf("%d\n",a[i]);
      if(num-a[i]>0)
      {
        printf("%d",num-a[i]);
        printf("%c",i==0?'\n':' ');
      }
    }
  }
  return 0;
}