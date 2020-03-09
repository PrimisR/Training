#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    char s1[25],s2[25];
    while(scanf("%s %s",s1,s2)!=EOF){
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int cnt = 0,cnt1 = 0;
        bool flag = false;
        for(int i=0;i<len1;i++){
            if(s1[i]=='_') flag = true,i++;
            if(flag){
                s1[cnt++] = s1[i];
            }
        }
        flag = false;
        for(int i=0;i<len2;i++){
            if(s2[i]=='_') flag = true,i++;
            if(flag){
                s2[cnt1++] = s2[i];
            }
        }
        for(int i=0;i<cnt;i++) printf("%c",s1[i]);
        printf("_small_");
        for(int i=0;i<cnt1;i++) printf("%c",s2[i]);
        printf("\n");
    }
    return 0;
}