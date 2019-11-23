#include <stdio.h>

#define N 100

int hp_a;
int hp_b;
int n;
int cry_a[N];
int cry_b[N];
int ges_a[N];
int ges_b[N];
int drk_a;
int drk_b;
char loser;

int main(){
	while(~scanf("%d %d",&hp_a,&hp_b)){
	scanf("%d",&n);
	drk_a=0;
	drk_b=0;
	for(int i=0;i<n;i++)//要先全部读入 
		scanf("%d %d %d %d",&cry_a[i],&ges_a[i],&cry_b[i],&ges_b[i]);
	for(int i=0;i<n;i++) 
	{
		if(ges_a[i]!=ges_b[i])
			{
				if(ges_a[i]==(cry_a[i]+cry_b[i])){
					hp_a--;
					drk_a++;}
				if(ges_b[i]==(cry_a[i]+cry_b[i])){
					hp_b--;
					drk_b++;}				
			}
		if(hp_a<0){
			loser='A';
			break;}
		if(hp_b<0){
			loser='B';
			break;}
	}
	printf("%c\n",loser);
	if(loser=='A')
		printf("%d\n",drk_b);
	if(loser=='B')
		printf("%d\n",drk_a);
}
	return 0;
}
