#include <stdio.h>

int x;
int y;
int r;
int x1;
int x2;
int y1;
int y2;
int part1;
int part2;

int main()
{
	while(~scanf("%d %d %d %d %d %d %d",&x,&y,&r,&x1,&y1,&x2,&y2))
	{
		part1=((y2-y1)*(x-x1)-(x-y1)*(x2-x1))*((y2-y1)*(x-x1)-(x-y1)*(x2-x1));
		part2=r*r*((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
		if(part1==part2)	printf("1\n");
		if(part1<part2)		printf("2\n");
		if(part1>part2)		printf("0\n");
	}
	return 0;
}
