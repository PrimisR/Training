#include <cstdio>
#include <memory.h>

using namespace std;

char mark[1000000];
char s[1000000];

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        int len;
        scanf("%d",&len);
        getchar();
        for(int i=0;i<len;i++)
            s[i]=getchar();
        s[len-2]<s[len-1] ? mark[len-2]='<' : mark[len-2]='>';
        for(int i=len-3;i>=0;i--)
        {
            if(s[i]<s[i+1]) mark[i]='<';
            else if(s[i]>s[i+1]) mark[i]='>';
            else mark[i]=mark[i+1];
        }
        for(int i=0;i<len-1;i++)
            putchar(mark[i]);
        putchar('\n');
    }
    return 0;
}