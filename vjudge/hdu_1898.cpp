#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
 
int main()
{
    int T,A,B,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&A,&B,&N);
        int a = N%A,b = N%B;
        if(a == b)
            printf("Both!\n");
        else if(a < b)
            printf("Sempr!\n");
        else
            printf("Xiangsanzi!\n");
    }
    
    return 0;
}