#include <stdio.h>

int n;

int main(){
	while(scanf("%d",&n)==1){
	for(int r=1;r<=2*n-1;r++)
		{for(int c1=1;c1<r;c1++)
			printf(" ");
		for(int c2=2*n-1;c2>(r-1)*2;c2--)
			printf("*");
		printf("\n");}}	
	return 0;
}
