/**
 * 记忆化搜索
 * */
#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int result[21][21][21];

int w(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0) return 1;

    if(a>20||b>20||c>20) return w(20,20,20);

    if(result[a][b][c]) return result[a][b][c];

    if(a<b&&b<c) return result[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);

    return result[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

void init()
{
    memset(result,0,sizeof(result));
}

int main()
{
    init();
    int a,b,c;
    while(cin>>a>>b>>c&&!(a==-1&&b==-1&&c==-1))
    {
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
}