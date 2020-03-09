#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <math.h>
#include <stack>
#include <map>
#define rtl rt<<1
#define rtr rt<<1|1
typedef long long LL;
using namespace std;
const int MAX = 200+10;
const double eps = 1e-10;
const double PI = acos(-1.0);
int t, a, b, c;
int main()
{
    scanf("%d", &t);
    LL maxx, minn;
    while(t--)
    {
        cin>>a>>b>>c;
        maxx = minn = 0;
        int k = 1;
        for(int i = 1; i<=a; ++i)
        {
            minn+=(LL)300*(2*k-1);
            k++;
        }
        for(int i = 1; i<=b; ++i)
        {
            minn+=(LL)100*(2*k-1);
            k++;
        }
        for(int i = 1; i<=c; ++i)
        {
            minn+=(LL)50*(2*k-1);
            k++;
        }
        k = 1;
        for(int i = 1; i<=c; ++i)
        {
            maxx+=(LL)50*(2*k-1);
            k++;
        }
        for(int i = 1; i<=b; ++i)
        {
            maxx+=(LL)100*(2*k-1);
            k++;
        }
        for(int i = 1; i<=a; ++i)
        {
            maxx+=(LL)300*(2*k-1);
            k++;
        }
        cout<<minn<<" "<<maxx<<endl;
    }
 
    return 0;
}