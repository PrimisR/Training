#include <iostream>
#include <stdio.h>
using namespace std;
int height[52];
int main(int argc, char const *argv[])
{
	int ncase;
	cin >> ncase;
	while(ncase--)
	{
		int len;
		int count = 0;
		cin >> len;
		for (int i = 0; i < len; ++i)
		{
			cin>>height[i];
		}
		if (len <= 2)
		{
			count = 0;
		}
		else for (int i = 1; i < len-1; ++i)
		{
			if (height[i]>=height[i-1]&&height[i]>=height[i+1]	)
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}