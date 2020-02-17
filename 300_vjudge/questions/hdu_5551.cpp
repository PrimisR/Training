#include <stdio.h>

int main()
{
    int K=1,N;
    for(scanf("%d",&N);N--;){
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",K++,2*n-1);
    }
    return 0;
}