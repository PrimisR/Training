#include<stdio.h>
#include<string.h>
int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0)  break;
		printf("%d\n",(n-1)/2);
	}
}