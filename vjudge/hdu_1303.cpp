#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
int i, cnt, a[maxn];

int main()
{
    int x;
    while(~scanf("%d", &a[1]) && a[1] != -1){
        i = 2, cnt = 0;
        while(~scanf("%d", &a[i]) && a[i] != 0){
            i++;
        }
        for(int j = 1; j <= i - 1; j++){
            for(int k = 1; k <= i - 1; k++){
                if(a[j] == 2 * a[k]) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}