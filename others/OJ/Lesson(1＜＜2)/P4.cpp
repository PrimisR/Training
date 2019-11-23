#include <stdio.h>

int h;
float weight;

int main()
{
	while(~scanf("%d",&h))
	{
		weight=((float)h-100.0)*0.9*2.0;
		printf("%0.1f\n",weight);
	}
}
