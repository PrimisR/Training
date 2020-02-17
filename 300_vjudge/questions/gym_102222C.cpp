/**
 * 循环取余
 * */
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll QP(ll x,ll n,ll Mod){
	  ll res=1;
	  while(n){
	  	  if(n&1){
	  	  	res=(res*x)%Mod;
			}
			x=(x*x)%Mod;
			n>>=1;
	  }
	  return res;
}
int main(){
   int T;
   cin>>T;
   string s[3];
   int g=1;
   while(T--){
   		int n, m;
   		cin>>n>>m;
   	   cin>>s[0]>>s[1]>>s[2];
   	   int t=s[1][0]-s[0][0];
   	   char ans[10000];
   	   int i;
   	   for( i=0; i<m; i++){
   	   		ans[i]=(s[2][i]-'A'-t+26)%26+'A';//先转化为数字，然后再转化为字母
		  }
		  ans[i]='\0';//注意这里要加结尾符号
		  printf("Case #%d: %s\n",g++,ans);

   }
	return 0;
}