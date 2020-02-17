/**
 * 经典抽球问题，先抽后抽概率是一样的都是 1/n，因为是在先前没有抽到的条件下抽下一个
 * 但是如果球的总数是奇数个，那么会多出来一次给先手抽，所以奇数先手大
 * */
#include <cstdio>
int main(){
    int k;
    while(~scanf("%d",&k)){
        if(k&1)
            printf("0\n");
        else
            printf("1\n");
    }
}