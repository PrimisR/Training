#include<stdio.h>

int hour;
int minute;

int main(){
	while(~scanf("%d:%d",&hour,&minute)){
	if((hour>=0&&hour<12)||hour==12&&minute==0)
		printf("Only %02d:%02d.  Too early to Dang.",hour,minute);
	else{
		if(minute)
			for(int i=1;i<=hour-12+1;i++)
				printf("Dang");
		else
			for(int i=1;i<=hour-12;i++)
				printf("Dang"); }
	printf("\n");
}
	return 0;
}
