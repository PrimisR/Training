#include<cstdio>
#include<iostream>

using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--) {
		scanf("%d",&n);
		if(n % 2 == 1) {
			puts("Balanced");
		}
		else puts("Bad");
	}
	return 0 ;
}