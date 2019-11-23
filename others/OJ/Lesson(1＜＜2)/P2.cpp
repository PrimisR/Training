#include <stdio.h>

int n;
int num[1000];
int odd;
int even;

int main()
{
	while(~scanf("%d",&n)){
	odd=0;
	even=0;
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(int i=0;i<n;i++)
		if(num[i]%2==0)
			even++;
		else
			odd++;
	printf("%d %d\n",odd,even);
}
} 
