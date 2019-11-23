#include <stdio.h>
#include <string.h>

#define a(x) x/100
#define b(x) (x/10)%10
#define c(x) x%10

char buf[99];

int main()
{
	int abc,def,ghi;
	int count;
	for(abc=123;abc<=333;abc++)
	{
		count=0;
		def=abc*2;
		ghi=abc*3;
		sprintf(buf,"%d%d%d%d%d%d%d%d%d",a(abc),b(abc),c(abc),a(def),b(def),c(def),a(ghi),b(ghi),c(ghi));
		for(int i='1';i<='9';i++)//为什么要按照字符比较而不是数字？ 
				if(strchr(buf,i))	count++;
		if(count==9)
			printf("%d %d %d\n",abc,def,ghi);
	}
	return 0;
} 
