#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctime>
#define MAXN 52222
#define MAXM 222222
#define INF 1000000001
using namespace std;
double p11, p10, p00;
int ct[] = {1, 6, 15, 20, 15, 6, 1};
int main() {
    double sum1 = 0, sum2 = 0;
    for(int i = 0; i <= 6; i++) sum1 += i * i * i * ct[i], sum2 += i * i * ct[i];
    sum1 /= 216.0, sum2 /= 36.0;
    p11 = sum1 / sum2;
    sum1 = 0, sum2 = 0;
    for(int i = 0; i <= 6; i++) sum1 += i * i * (6 - i) * ct[i], sum2 += i * (6 - i) * ct[i];
    sum1 /= 216.0, sum2 /= 36.0;
    p10 = sum1 / sum2;
    sum1 = 0, sum2 = 0;
    for(int i = 0; i <= 6; i++) sum1 += i * (6 - i) * (6 - i) * ct[i], sum2 += (6 - i) * (6 - i) * ct[i];
    sum1 /= 216.0, sum2 /= 36.0;
    p00 = sum1 / sum2;

    int T, m, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &m, &n);
        int s = m + n;
        int num1 = s / 2;
        int num2 = s % 2;
        int num3 = 4 - num1 - num2;
        printf("%.3f\n", p11 * num1 + p10 * num2 + p00 * num3);
    }
    return 0;
}