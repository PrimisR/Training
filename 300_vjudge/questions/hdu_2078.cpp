//由于是从最简单的开始，而初始化效率值是100，故找出最小值，他们之间的差的平方就是最高效率值。
#include <stdio.h>
int main()
{
	int t, n, m, a, min_a;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		min_a = 100;
		while(n--)
		{
			scanf("%d", &a);
			if(min_a > a)
				min_a = a;
		}
		printf("%d\n", (100-min_a) * (100-min_a));
	}
	return 0;
}