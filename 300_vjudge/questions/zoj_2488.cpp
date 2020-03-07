#include<stdio.h>
#include<stdlib.h>
 
static int cmp(const void *p1, const void *p2)
{
	return *(int *) p1 - *(int *) p2;
}
 
static int max(int a, int b)
{
	return a > b ? a : b;
}
 
int main()
{
	int t, n, a[1000];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int i, res = -1;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), cmp);
		for (i = 0; i < n; i++)
			res = max(res, a[i] * (n - i));
		printf("%d\n", res);
	}
	return 0;
}