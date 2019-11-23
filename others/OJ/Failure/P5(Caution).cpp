#include <stdio.h>
#include <math.h>

int n;
int scannum[100];
int scandeno[100];
int tempnum;
int tempdeno;
int num;
int deno;

int gcd(int p,int q){
	int r;
	if(p<q){r=p; p=q; q=r;}
	if(p!=0&&q!=0){
	r=p%q;
	while(r!=0){
		p=q;
		q=r;
		r=p%q;}}
	return(q);
} 

int main(){
	while(scanf("%d",&n)==1){
	tempdeno=1;
	tempnum=0;
	for(int i=0;i<n;i++)
		scanf("%d/%d",&scannum[i],&scandeno[i]);
	for(int i=0;i<n;i++)
		tempdeno*=scandeno[i]; 
	for(int i=0;i<n;i++)
		tempnum+=scannum[i]*tempdeno/scandeno[i];
	if(tempnum!=0){
	num=tempnum/abs(gcd(tempnum,tempdeno));
	deno=tempdeno/abs(gcd(tempnum,tempdeno));}
	else
	{num=0;deno=1;}
	if(num/deno&&num)
		{if(num%deno)
		printf("%d %d/%d\n",num/deno,num%deno,deno);
		else
		printf("%d\n",num/deno);}
	else if(num/deno==0&&num){
		if(num%deno)
		printf("%d/%d\n",num,deno);}
	else
	printf("0\n");
}
	return 0;
}
