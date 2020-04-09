#include<iostream>
using namespace std;
int num[20],n;
void find(int i,int finded,int shows[])
{
	int show[7],j;
	for(j=1;j<7;j++)
		show[j]=shows[j];
	show[finded]=i-1;
	
	if(finded==6)
	{
		for(i=1;i<7;i++)
			cout<<num[show[i]]<<" ";
		cout<<endl;
		return ;
	}
	for(;i<=n-(5-finded);i++)
		find(i+1,finded+1,show);
}
int main()
{
	int i,j;
	while(cin>>n&&n)
	{
		int show[7];
		for(i=1;i<=n;i++)
			cin>>num[i];
		for(i=1;i<=n-5;i++)
			find(i+1,1,show);
		cout<<endl;
	}
	return 0;
}