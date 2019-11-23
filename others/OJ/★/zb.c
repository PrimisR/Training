#include <stdio.h>
#include <string.h>
#define N 10001
int len;
int cnt[10];
char num[N];
int main() {
	scanf("%s",num);
	len=strlen(num);
	for (int i=0;i<len;i++)
		cnt[num[i]-'0']++;
	for (int i=0;i<10;i++)
		if (cnt[i])
			printf("%d:%d\n",i,cnt[i]);
	return 0;
}