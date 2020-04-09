#include<iostream>
using namespace std;

int main()
{
	int t;
	int n,b;
	int Max,Min;
	cin>>t;
	while(t--)
	{
		Max = 0;
		Min = 100;
		cin>>n;
		for(int i = 0;i<n;i++)
		{
			cin>>b;
			if(b>Max)
				Max = b;
			if(b<Min)
				Min = b;
		}
		cout<<(Max-Min)*2<<endl;
	}
	return 0;
}