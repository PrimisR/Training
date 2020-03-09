#include <iostream>
#include <cstdio>
#include <cstring>
 
 
using namespace std;
const int maxn = 1e3 + 5;
int a[maxn];
 
int main(){
    int n;
    while(cin >> n){
        memset(a, 0, sizeof(a));
        for(int i = 0; i <= n; ++i){
            int x;
            scanf("%d", &x);
            ++a[x];
        }
        for(int i = 1; i <= n; ++i)
        if(a[i] == 2){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}