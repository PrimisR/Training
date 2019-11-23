#include<stdio.h>
int main()
{
	int i,j,n,p,speed;
	printf("Please put in the height of Starwave you want to see(less than 115):");
	scanf("%d",&n);
	printf("Please put in the speed(more than 20000000,the bigger,the slower):");
	scanf("%d",&speed);
	loop:
	j=1;
	while(j<=n)
	{
		for(p=0;p<=speed;p++)
			{
				;
			}	//Delay(Speed)
		i=n;
		while(i>=j)
		{
		printf("*");
		i--;
		}
		printf("\n");
		j++;
	}
	goto loop;
	return 0;
 } 
