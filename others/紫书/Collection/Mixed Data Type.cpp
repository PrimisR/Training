#include<stdio.h>
int main()
{
	int count;
	char code;
	float ratio;
	char name[15];
	scanf("%d%c%f%s",&count,&code,&ratio,name);//�ո� 
	if(scanf("%d%c%f%s",&count,&code,&ratio,name)==4) 
	printf("%d %c %f %s",count,code,ratio,name);
	else
	printf("Error in Input");
 } 
