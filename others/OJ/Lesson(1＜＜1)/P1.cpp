#include <stdio.h>
#include <string.h>

double digit;
int len;
double iseven;
double isminus;
double two; 
double degree;
char num[100];

int main(){
	while(scanf("%s",num)==1){
	len=strlen(num);
	two=0;
	if(num[0]=='-') {digit=len-1; isminus=1;} 
	else {digit=len; isminus=0.0;}
	if(num[len-1]%2) iseven=0.0; 
	else iseven=1.0;//'0'=48 
	for(int i=0;i<len;i++)
		if(num[i]=='2')
			two++;
	degree=two/(digit)*(1.0+isminus*0.5)*(1.0+iseven*1.0);
	printf("%.2lf%%\n",degree*100);}
	return 0;
} 
