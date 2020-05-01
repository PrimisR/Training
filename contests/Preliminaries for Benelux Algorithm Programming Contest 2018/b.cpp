#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char visit[1005][1005];
int n, m;
int sun, sum;
int a[1000005];
int z = 0;
int mov1[6][2] = { 1,0,-1,0,0,1,0,-1,-1,1,1,1 };//右 
int mov2[6][2] = { 1,0,-1,0,0,1,0,-1,1,-1,-1,-1 };//左
int cmp(int a, int b)
{
	return a > b;
}
bool check(int x,int y)
{
	if (x >= 1 && x <= n && y >= 1 && y <= m)
		if (visit[x][y] == '.')
			return true;
	return false;
}
void dfs(int x, int y)
{
	sum++;
	visit[x][y] = '#';
	for (int i = 0; i < 6; i++)
	{
		if (x % 2 == 0)
		{
			if (check(x + mov1[i][0], y + mov1[i][1]))
				dfs(x + mov1[i][0], y + mov1[i][1]);
		}
		else
			if (check(x + mov2[i][0], y + mov2[i][1]))
				dfs(x + mov2[i][0], y + mov2[i][1]);
	}
	return;
}
int main()
{
	cin >> sun >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> visit[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (visit[i][j] == '.')
			{
				sum = 0;
				dfs(i, j);
				a[z++] = sum;
			}
		}
	sort(a, a + z, cmp);
	int p = 0, s = 0;
	for (int i = 0; i <= z; i++)
	{
		if (s >= sun)
			break;
		s = s + a[i];
		p++;
	}
	printf("%lld\n", p);
	return 0;
}