#include <stdio.h>
#include <math.h>

int n;
long long scannum[100];
long long scandeno[100];
long long tempnum;
long long tempdeno;
long long num;
long long deno;

long long gcd(long long p,long long q){
	long long r;
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
		scanf("%lld/%lld",&scannum[i],&scandeno[i]);
	for(int i=0;i<n;i++)
		tempdeno*=scandeno[i]; 
	for(int i=0;i<n;i++)
		tempnum+=scannum[i]*tempdeno/scandeno[i];
	if(tempnum!=0){
	num=tempnum/abs(gcd(tempnum,tempdeno));
	deno=tempdeno/abs(gcd(tempnum,tempdeno));}
	else
	{num=0;deno=1;}
	if(num/deno)
		printf("%lld %lld/%lld\n",num/deno,num%deno,deno);
	else
		printf("%lld/%lld\n",num,deno);}
	return 0;
}
