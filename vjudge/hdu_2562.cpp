#include<stdio.h>
#include<string.h>
void swap(char &a,char &b){
    char t=a;
   a=b;b=t;
}
int main(){
    int c;
    char str[52];
   while(scanf("%d",&c)!=EOF){
       getchar();
       int i;
       while(c--){
           scanf("%s",str);
           for(i=0;str[i]!='\0';i=i+2)
               swap(str[i],str[i+1]);
           printf("%s\n",str);
       }
    }
    return 0;
}