#include <iostream>
#include <stdio.h>
#include <string.h>
#define READ() freopen("in.txt", "r", stdin);

using namespace std;

int Map(char ch)
{
    int n;
    switch(ch)
    {
        case 'I': n = 1;break;
        case 'V': n = 5;break;
        case 'X': n = 10; break;
        case 'L': n = 50; break;
        case 'C': n = 100; break;
        case 'D': n = 500; break;
        case 'M': n = 1000; break;
        default : n = 0;break;
    }
    return n;
}
int main()
{
    int T;
    char in[128];
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        gets(in);
        int ans = 0;
        int len = strlen(in);
        char pre, nxt;
        for (int i = 0; i < len; i++)
        {
            pre = in[i];
            if(i < len-1) nxt = in[i+1];
            else nxt = ' ';
            if (Map(pre) >= Map(nxt)) ans+= Map(pre);
            else ans -= Map(pre);
        }
        printf("%d\n", ans);
    }
    return 0;
}