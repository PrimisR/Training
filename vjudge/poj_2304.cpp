/* POJ2304 ZOJ1928 UVA10550 Combination Lock */

#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 40;

int main()
{
    int p, a, b, c;
    while(~scanf("%d%d%d%d", &p, &a, &b, &c) && (p || a || b || c)) {
        int ans = MN * 3;           // 第1步+第3步共转3圈，每圈40格
        ans += (p - a + MN) % MN;
        ans += (b - a + MN) % MN;
        ans += (b - c + MN) % MN;
        printf("%d\n", ans * 360 / MN);     // 格转度数（360度=40格）
    }

    return 0;
}