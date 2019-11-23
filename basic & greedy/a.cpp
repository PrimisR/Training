#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>

struct spair{
	int left;
	int right;
};

using namespace std;

int mark[2000];

int cmp(int a,int b) {
	return a>b;
}

int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
    	int n;
    	memset(mark,0,sizeof(mark));
    	spair pairs[2000];
        cin>>n;
        for(int i=0;i<n;i++)
        {
        	cin>>pairs[i].left>>pairs[i].right;
        	if(pairs[i].left>pairs[i].right) swap(pairs[i].left,pairs[i].right);
        	if(!pairs[i].left%2) pairs[i].left/=2;
        	else pairs[i].left=(pairs[i].left+1)/2;
        	if(!pairs[i].right%2) pairs[i].right/=2;
        	else pairs[i].right=(pairs[i].right+1)/2;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=pairs[i].left;j<=pairs[i].right;j++)
			{
				mark[j]++;
			}
		}
		sort(mark,mark+2000,cmp);
		cout<<mark[0]*10<<endl;
    }
}
