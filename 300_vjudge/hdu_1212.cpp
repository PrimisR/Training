#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstring>
#include<string> 
using namespace std;
string s;
long long  Mod;
int main()
{
	int i;
	while(cin>>s>>Mod){
		long long ans=0,p=1;
	    int L=s.length()-1;
	    for(i=0;i<=L;i++){
	        ans=(ans*10+s[i]-'0')%Mod;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}