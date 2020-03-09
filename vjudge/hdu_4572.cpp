#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
	int n,m;
	while(~scanf("%d%d",&m,&n))
	{
		int sum=0,k=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				sum+=(m-k);
				k++;
			}
			else sum+=(m-k);
		}
		printf("%d\n",sum);
	}
	return 0;
}
