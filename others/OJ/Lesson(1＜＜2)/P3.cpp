#include <stdio.h>
#include <math.h>

int n;
long long num[10];
int composite; 

int main()
{
	while(~scanf("%d",&n)){	
	for(int i=0;i<n;i++)
		scanf("%lld",&num[i]);
	for(int i=0;i<n;i++)
	{
		composite=0;
		if(num[i]==1)
			printf("No\n");
		else
		{
			if(num[i]%2==0&&num[i]!=2)
				printf("No\n");
			else
			{
				for(int j=3;j<sqrt(num[i])+1;j+=2)//省掉一半2,
				//此处最好用四舍五入，floor(x+0.5)
					if(num[i]%j==0)
					{
						composite=1;
						break;
					}
				if(composite)
					printf("No\n");
				else
					printf("Yes\n");
		}
		}
	}
}
} 
