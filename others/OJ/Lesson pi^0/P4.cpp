#include <stdio.h>

int a;
int b;
int sum;
int count;

int main(){
	while(scanf("%d %d",&a,&b)==2){
	count=0;
	sum=0;//记得循环中清零 
	for(int i=a;i<=b;i++){
		printf("%5d",i);
		count++;
		if(count==5){
			printf("\n");
			count=0;}}
	for(int i=a;i<=b;i++)
		sum+=i;
	printf("\nSum = %d\n",sum);
}
	return 0;
} 
