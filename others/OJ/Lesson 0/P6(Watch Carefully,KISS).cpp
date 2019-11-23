#include <stdio.h>
#include <string.h>
#define N 28

char cap[N];
int count;
int len;

int main(){
	while(scanf("%s",cap)==1){
	count=0;
	len=strlen(cap);
	for(int i=0;i<len;i++){
		if(cap[i]==cap[i+1]){
			printf("No\n"); 
			break;}	
		count++;}
	if(count==27)
		printf("Yes\n");}
}
