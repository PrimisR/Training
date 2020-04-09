#include<iostream>
#include<cstring>
using namespace std;
 
int main()
{
	int i,k,base[31],sum;
	char skew[32];
	base[0] = 1;
	for(i = 1;i<31;i++) base[i] = 2*base[i-1] + 1;
	while(1)
	{
		cin>>skew;
		if(strcmp(skew,"0") == 0)
			break;
		sum = 0;
		k = strlen(skew);
		for(i = 0 ;i<strlen(skew);i++)
		{
			k--;
			sum+=(skew[i] - '0')*base[k];
		}
		cout<<sum<<endl;
	}
	return 0;
}