#include<stdio.h>
int main(){
	int n,t,m;
	scanf("%d",&n);
	while(n--){
		m=3;
	 scanf("%d",&t);
	 for(int i=0;i<t;i++)
	 	m+=m-2;	
	 printf("%d\n",m);
	}
	return 0; 
}