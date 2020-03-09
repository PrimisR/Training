#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cstring>
#define INF 0x3f3f3f3f
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;
const int maxn = 1e6 + 10;

char a[10][30] = { 0 };

int solve(int p)
{
	if (a[3][p + 1] == '.')
	{
		if (a[6][p + 1] == 'X') return 0;
		if (a[0][p + 1] == 'X') return 7;
		return 1;
	}
	if (a[1][p] == '.')
	{
		if (a[4][p] == 'X') return 2;
		return 3;
	}
	if (a[1][p + 3] == '.')
	{
		if (a[4][p] == '.') return 5;
		return 6;
	}
	if (a[4][p] == '.')
	{
		if (a[6][p + 1] == '.') return 4;
		return 9;
	}
	return 8;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ms(a, 0);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				scanf(" %c", &a[i][j]);
			}
		}
		int h1, h2, m1, m2;
		for (int i = 0; i < 4; i++)
		{
			int p;
			if (i == 0) p = 0;
			else if (i == 1) p = 5;
			else if (i == 2) p = 12;
			else p = 17;
			if (i == 0) h1 = solve(p);
			else if (i == 1) h2 = solve(p);
			else if (i == 2) m1 = solve(p);
			else m2 = solve(p);
		}
		printf("%d%d:%d%d\n", h1, h2, m1, m2);
	}
	return 0;
}
