/**
 * A和B两人在1~N中选数字。已知1<=X<=N，谁先选中X谁就输。
 * 每当一个人选出一个不是X的数，裁判都会说明这个数比X大还是小，与此同时，可选范围随之缩小。
 * 已知A先选，求满足能让B赢的条件下X的个数。
 * ※
 * 每次A平衡于B选，A是最优策略
 * 只有n为奇数并且X位于正中央，A才会优先打破平衡
 * */
#include <cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        printf("%d\n", N & 1);
    }
    return 0;
}