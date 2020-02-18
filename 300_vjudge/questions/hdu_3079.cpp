#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int i,j,k;
	char a[233];
	cin>>i; 
	while(i--){
		cin>>a;
		k=strlen(a);
		for(j=0;j<k;j++)
		if(a[j]<='Z') a[j]+=32;
		for(j=0;j<k;j++)
		if(a[j]=='a'||a[j]=='e'||a[j]=='i'||a[j]=='o'||a[j]=='u')
		a[j]-=32;
		for(j=0;j<k;j++)
		cout<<a[j];
		cout<<endl;
	}
	return 0;
 }