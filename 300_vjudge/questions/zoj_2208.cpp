#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
 
using namespace std;
 
#define LL long long
const int INF=0x3f3f3f3f;
 
char ch[1000];
char s[1000][1000];
 
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%s",ch);
        int len=strlen(ch);
        int cnt=0;
        for(int i=0; i<len/n; i++)
        {
            if(i%2==0)
            {
                for(int j=0; j<n; j++)
                    s[i][j]=ch[cnt++];
            }
            else
            {
                for(int j=n-1; j>=0; j--)
                    s[i][j]=ch[cnt++];
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<len/n; j++)
            {
                printf("%c",s[j][i]);
            }
        } printf("\n");
    }
    return 0;
}