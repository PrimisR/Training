#include<iostream>   
#include <cstring>
using namespace std;  
int main()  
{  
	int ncase;
	cin>>ncase;
	while(ncase--){
		int n,m;
		int sum=0;
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			for(int j=0;i+j<=n;j++){
				int k=n-i-j;
				if(i+j*2+k*5==m)sum++;
			}
		}
		cout<<sum<<endl;
	}
    
    
    return 0;  
}  