#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int main(){
	
	int T,N;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int sum = 0;
		for(int i=1 ; i<=N ; ++i){
			int a,b;
			scanf("%d %d",&a,&b);
			sum += a*b;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}