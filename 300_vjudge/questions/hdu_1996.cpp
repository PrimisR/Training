/**
 * n个盘子放三列，有3^n放法，并且每个放置方法只有一种情况就是从小到大
 * */
#include<stdio.h>
#include<math.h>

typedef long long ll; 

int main(){
	
	ll value[35];
	int t = 0;
	int n = 0;
	
	for(int i = 0;i <= 30;i++){
		value[i] = pow(3,i);
	}
	
	scanf("%d",&t);
	
	while(t--){
		
		scanf("%d",&n);
		printf("%lld\n",value[n]);
	}
	
	
	
	return 0;
}