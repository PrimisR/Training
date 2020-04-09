#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
 
int main()
{ 
    int num;
    while(cin>>num&&num!=-1)
    {
    	int res=0;
    	int speed,t1=0,t;
    	while(num--)
    	{
    		cin>>speed>>t;
    		res+=speed*(t-t1);
    		t1=t;
		}
		cout<<res<<" miles"<<endl;
	}
	return 0;
 } 