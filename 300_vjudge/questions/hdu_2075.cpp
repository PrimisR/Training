#include <cstdio>
#include <algorithm>
using namespace std;
int main(void){
    int t;
    scanf("%d",&t);
    long long a,b;
    while(t--){
        scanf("%lld%lld",&a,&b);
        if(a%b==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}