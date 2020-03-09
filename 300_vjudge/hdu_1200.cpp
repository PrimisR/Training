#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,len,m,e,j;
    char str[10000],ch[1000][25];
    while(scanf("%d",&n)==1&&n)
    {
        getchar();
        scanf("%s",str);
        len=strlen(str);
        m=len/n;//把str串分成m个小串
        if(len%n)
        m++;
        for(i=0;i<m;i++)
        if(i%2==0)//当能被2整除的就正向保存
        {
            e=0;
             for(j=i*n;j<len&&j<(i+1)*n;j++)
                ch[i][e++]=str[j];
        }
        else//否则就倒着保存
        {
            e=0;
            for(j=(i+1)*n-1;j>=i*n;j--)
            if(str[j]!='\0')
            ch[i][e++]=str[j];
        }
        e=len%n;//注意,有的不能除尽,最后一个小串长度小于n
        for(j=0;j<n;j++)
        for(i=0;i<m;i++)
        if(i==m-1)//最后一个小串输出
        {
            if(j<e||e==0)
            printf("%c",ch[i][j]);
        }
        else
        printf("%c",ch[i][j]);
 
        printf("\n");
    }
}