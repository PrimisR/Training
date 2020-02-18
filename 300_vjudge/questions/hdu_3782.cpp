#include <stdio.h>
 
int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF && n) {
        int cnt = 0;
 
        while(n != 1) {
            if(n % 2)
                n = (3 * n + 1) / 2;
            else
                n /= 2;
 
            cnt++;
        }
 
        printf("%d\n", cnt);
    }
 
    return 0;
}