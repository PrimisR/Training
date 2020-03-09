/**
 * 有两种蘑菇，好蘑菇捡到会加一点血，坏蘑菇捡到会掉ｍ点血，
 * 有m*k+1个好蘑菇和k个坏蘑菇随机排列，问按顺序吃蘑菇能活着的概率是多少。
 * Raney引理:
 * */
#include<cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Case #%d: %.8f\n",i,1.0/(a*b+1+b));
    }
}