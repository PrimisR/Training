#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int t,n,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int count=0;
		scanf("%d%d",&n,&m);
		while(n&&m)
		{
			if(n<m)
			{
				m-=n;
				count++;
			}
			else 
			{
				n-=m;
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}