#include<iostream>
using namespace std;
int main()
{
    int a[30][30],n;
    int x,y,i,j;
    while(cin>>n,n)
    {
        y=(n+1)/2;
        x=y+1;
        for(i=1;i<=n*n;i++)
        {
            a[x][y]=i;//a[x][y]=1:将1放在第n行中间一列
            if(i%n==0)//i为n的倍数时,下一个数将出现在此数下方二格
                x+=2;
            else//否则将出现在右下格
            {
                x+=1;
                y+=1;
            }
            if(x>n)
                x-=n;
            if(y>n)
                y-=n;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%4d",a[i][j]);//右对齐%4d，左对齐%-4d
            printf("\n");
        }
    }
}