#include <stdio.h>

int n;
char c;

int main(){
	while(scanf("%d %c",&n,&c)==2){
	getchar();
	for(int i=1;i<=(n+1)/2;i++)
		{for(int j=1;j<=n;j++)
			printf("%c",c);
		printf("\n");}}
	return 0;
} 
