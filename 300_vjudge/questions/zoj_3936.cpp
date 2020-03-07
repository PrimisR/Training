#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 4;
int T, a, b, c, d;
 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d %d\n%d %d\n", c, b + d, a, b + d);
	}
	return 0;
}