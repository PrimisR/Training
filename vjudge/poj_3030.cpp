#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	long long a, b, c;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b>>c;
		if(b - c > a)
		{
			cout<<"advertise"<<endl;
		}
		else if (b - c < a)
		{
			cout<<"do not advertise"<<endl;
		}
		else
			cout<<"does not matter"<<endl;
	}
	return 0;
}