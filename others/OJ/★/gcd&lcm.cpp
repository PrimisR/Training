#include <stdio.h>

int n;
long long num[100];
long long deno[100];
long long tempnum;
long long tempdeno; 

long long gcd(long long p,long long q){
	long long r;
	if(p<q){r=p; p=q; q=r;}
	if(p&&q){
	r=p%q;
	while(r){
		p=q;
		q=r;
		r=p%q;}
	return(q);}
} 

long long lcm(long long p,long long q){
	long long m;
	if(p&&q){
	m=p/gcd(p,q)*q;
	return(m);}
}

long long abs(long long i){
	if(i>=0)
	return i;
	else
	return -i;
}

int main(){
	while(scanf("%d",&n)==1){
	for(int i=0;i<n;i++)
		scanf("%lld/%lld",&num[i],&deno[i]);
	for(int i=0;i<n-1;i++){
		tempdeno=abs(lcm(deno[i],deno[i+1]));
		tempnum=num[i]*tempdeno/deno[i]+num[i+1]*tempdeno/deno[i+1];
		if(tempnum){
			num[i+1]=tempnum/abs(gcd(tempdeno,tempnum));
			deno[i+1]=tempdeno/abs(gcd(tempdeno,tempnum));}
		else
			{num[i+1]=0;
			deno[i+1]=1;}}
	if(num[n-1]/deno[n-1])		
		printf("%lld %lld/%lld\n",num[n-1]/deno[n-1],num[n-1]%deno[n-1],deno[n-1]);
	else
		printf("%lld/%lld\n",num[n-1]%deno[n-1],deno[n-1]);
}
	return 0;
}
