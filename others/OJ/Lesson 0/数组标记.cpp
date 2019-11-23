#include<stdio.h>
#include <string.h>
char num[1100];
int main()
{	
	while(~scanf("%s",num))
{
	getchar();
	int i,j,sta[10]={0};
	int len;
	len=strlen(num);//用来读取数组中赋值的部分
	for(i=0;i<len;i++) 
	{
		sta[num[i]-'0']++;
	}
	for(j=0;j<=9;j++)
	{
		if(sta[j])
		printf("%d:%d\n",j,sta[j]);
	}
}
	return 0;
} 
