/**
 * 求原点到其他各个点的最短路的最大值
 * Dijkstra
 * */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
 
const int N = 105;
const int MAX = 0xfffffff;
int edge[N][N];
int n, e;
int mindis[N];
bool vis[N];
 
void init()
{
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j)
		{
			edge[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i) 
	{
		vis[i] = false;
		mindis[i] = MAX;
	}
}
 
void dijkstra(int s)
{
	int pos, te, tm;
	mindis[s] = 0;
	vis[s] = true;
	pos = s;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!vis[j] && edge[pos][j] != -1 &&  mindis[pos] + edge[pos][j] < mindis[j])
			{
				mindis[j] = mindis[pos] +edge[pos][j];
			}
		}
		tm = MAX;
		for (int j = 0; j < n; ++j)
		{
			if (!vis[j] && mindis[j] < tm)
			{
				tm = mindis[j];
				te = j;
			}
		}
		vis[te] = true;
		pos = te;
	}
}
 
int strtoint(char* str)
{
	if (str[0] == 'x') return -1;
	int ret = 0;
	while (*str)
	{
		ret = ret * 10 + *str++ - '0';
	}
	return ret;
}
 
int main()
{
	char str[35];
	int dis;
	scanf("%d", &n);
	init();
	for (int i = 0; i < n; ++i)
	{
		edge[i][i] = 0;
		for (int j = 0; j < i; ++j)
		{
			scanf("%s", str);
			dis = strtoint(str);
			edge[i][j] = edge[j][i] = dis;
		}
	}
	dijkstra(0);
	int tmax = -1;
	for (int i = 1; i < n; ++i)
	{
		if (mindis[i] > tmax) tmax = mindis[i];
	}
	printf("%d\n", tmax);
	return 0;
}