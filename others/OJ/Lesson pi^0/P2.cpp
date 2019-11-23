#include <stdio.h>

int n;
int total;

int main(){
	while(scanf("%d",&n)==1){
		total=1;
		for(int i=1;i<=n;i++)
			total=total*2;
	printf("2^%d = %d\n",n,total);
	}
	return 0;
} 
