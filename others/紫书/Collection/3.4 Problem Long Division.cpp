#include <stdio.h>
#include <string.h>

int count;
char s[20];
char buffer[99];
int x;
int y;
int z;


int main()
{
	scanf("%s",s);
	for(int abc=100;abc<=999;abc++)//abc和de均为变量名 
		for(int de=10;de<=99;de++)
		{
			x=abc*(de%10);//竖式第一步 
			y=abc*(de/10);//竖式第二步 
			z=abc*de;//竖式结果
			sprintf(buffer,"%d%d%d%d%d",abc,de,x,y,z);
			//将所有整数打印入缓存区， 整数是按数字输入的
			int ok=1;
			for(int i=0;i<strlen(buffer);i++)//逐个比较 
				if(strchr(s,buffer[i])==NULL)//字符与字符串比较strchr
					ok=0;
			if(ok)
			{
				printf("<%d>\n",++count);//计数器 
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
			}
		} 
		printf("The number of solutions=%d\n",count);
		return 0;
}
