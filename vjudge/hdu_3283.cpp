#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
char str[100];
 
int main()
{
	int num_case,ca;
	cin>>num_case;
	while(num_case--)
	{
		scanf("%d %s",&ca,str);
		if(next_permutation(str,str+strlen(str)))
			cout<<ca<<" "<<str<<endl;
		else 
			cout<<ca<<" BIGGEST"<<endl;
	}
	return 0;
}