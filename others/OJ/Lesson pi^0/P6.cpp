#include <stdio.h>

int a;
int b;
int c;
int t;
//交换变量法 
int main(){
	while(scanf("%d %d %d",&a,&b,&c)==3){
	if(a>b) {t=a; a=b; b=t;}
	if(a>c) {t=a; a=c; c=t;}
	if(b>c) {t=b; b=c; c=t;}
	printf("%d->%d->%d\n",a,b,c);
	}
	return 0; 
}
