#include<stdio.h>
int main()
{
	int row,n;
	for(row=1;row<=5;row++)
	{
		for(n=1;n<=row;n++)
		{
		printf("%d",n);
		}
		printf("\n");
	}
	return 0;
}
