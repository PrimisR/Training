#include<stdio.h>
#include<string.h>
char a[50][50];
int main()
{
    int i,j,n,m,num,k=1;
    scanf("%d",&n);
    while(n--)
    {
       scanf("%d",&m);
       memset(a,0,sizeof(a));
       num=10-(m/10)+1;
       for(i=0;i<12;i++)
       {
           for(j=0;j<14;j++)
           {
             if(i==0||i==11)
             {
               if(j==0||j==13)
               a[i][j]='*';
               else
               a[i][j]='-';
             }
             else 
             if(j==0||j==13)
             {
                a[i][j]='|'; 
             }
             else
             {
                 if(num>0)
                 {
                   a[i][j]='.';
                 }
                 else
                 a[i][j]='-';
             }
           }
           num--;
       }
       printf("Case #%d:\n",k++);
       for(i=0;i<12;i++)
       {
          for(j=0;j<14;j++)
          printf("%c",a[i][j]);
          puts("");
       }
    }
    return 0;
}