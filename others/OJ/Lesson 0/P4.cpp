#include <stdio.h>

#define N 1000
#define LEN 100

int n;
int m;
char info[N][LEN];
int num1[N];
int num2[N];
int target[N];

int main(){
while(scanf("%d",&n)==1)
{	for(int i=0;i<n;i++)
		scanf("%s %d %d",info[i],&num1[i],&num2[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",&target[i]);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(target[i]==num1[j])
			printf("%s %d\n",info[j],num2[j]);}
	return 0;
 } 
