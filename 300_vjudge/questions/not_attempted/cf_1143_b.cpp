/**
 * ※
 * 给定n，求不大于n的所有正整数中各个数位相乘最大的乘积
 * */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

//从最后一位开始,不断向前退位将此位变成9,或者不改变此位,然后取最大值
int ans(int n) {
    if(n == 0) return 1;
    if(n < 10) return n;
    return max(ans(n/10)*(n%10),ans(n/10-1)*9);
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d",ans(n));
}