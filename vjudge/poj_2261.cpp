#include <stdio.h>
#include <string.h>
const int N = 20;
const int d[5] = {1, 2, 4, 8, 16};
int i, j, k;
double v[N][N], dp[N - 10][N];
char name[N][105];
 
int main() {
	for (i = 1; i <= 16; i ++)
		scanf("%s",name[i]);
	for (i = 1; i <= 16; i ++)
		for (j = 1; j <= 16; j ++) {
			scanf("%lf", &v[i][j]);
		}
	for (i = 1; i <= 16; i ++)
		dp[0][i] = 100;
	for (k = 1; k <= 4; k ++) 
		for (i = 1; i <= 16; i ++)
			for (j = 1; j <= 16; j ++) {
				if ((i - 1) / d[k] == (j - 1) / d[k] && (i - 1) / d[k - 1] != (j - 1) / d[k - 1])
					dp[k][i] += dp[k - 1][i] * dp[k - 1][j] * v[i][j] / 10000;
			}
	for (i = 1; i <= 16; i ++) {
		printf("%-10s p=%.2f%%\n", name[i], dp[4][i]);
	}
	return 0;
}