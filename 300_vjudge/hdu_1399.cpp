#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
using namespace std;
int n;
int main()
{
    while(scanf("%d",&n)!=EOF,n){
        int ans = 1,ans1 = 1;
        for(int i=1;i<=1000;i++){
            if(i*i*i>n) break;
            ans = i;
        }
        for(int i=1;i<=1000;i++){
            if(i*(i+1)*(i+2)>6*n) break;
            ans1 = i;
        }
        int res = 0;
        for(int i=0;i<=ans+1;i++){
            for(int j=0;j<=ans1+1;j++){
                if(i*i*i+j*(j+1)*(j+2)/6>n) {
                    break;
                }
                res = max(res,i*i*i+j*(j+1)*(j+2)/6);
            }
        }
        printf("%d\n",res);
    }
}