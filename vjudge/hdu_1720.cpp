#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int work(char *x)
{
    int len,i,sum=0;
    len=strlen(x);
    for(i=0;i<len;i++)
    {
        if(x[i]>='A'&&x[i]<='F') sum=sum*16+(x[i]-'A'+10);
        if(x[i]>='a'&&x[i]<='f') sum=sum*16+(x[i]-'a'+10);
        if(x[i]>='0'&&x[i]<='9') sum=sum*16+(x[i]-'0');
    }
    return sum;
}

int main()
{
    char a[1000],b[1000];
    while(~scanf("%s %s",a,b))
        printf("%d\n",work(a)+work(b));
}