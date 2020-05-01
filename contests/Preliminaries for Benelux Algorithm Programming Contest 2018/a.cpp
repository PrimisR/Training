#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
char mp[110][110];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", mp[i] + 1);
	int num = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(mp[i][j] != '.')
			{
				ans += j;
				num++;
			}
		}
	}
	int l = 1e9, r = 0;
	for(int j = 1; j <= m; j++)
	{
		if(mp[n][j] != '.')
		{
			l = min(l, j);
			r = max(r, j);
		}
	}
	double ans1;
	ans1 = ans;
	ans1 /= num;
	int ans2 = ans1 + 0.5;
	if(ans2 < l) printf("left\n");
	else if(ans2 > r) printf("right\n");
	else printf("balanced\n");
	return 0;
}