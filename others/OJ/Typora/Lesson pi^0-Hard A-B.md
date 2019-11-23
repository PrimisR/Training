#### Lesson pi^0-Problem 1-Hard A-B

##### Problem Description

本题要求你计算A-B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，剩下的字符组成的就是字符串A-B。

##### Input

输入在2行中先后给出字符串A和B。两字符串的长度都不超过10^4，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。

##### Output

在一行中打印出A-B的结果字符串。

##### Sample Input

I love GPLT!  It's a fun game!
aeiou

##### Sample Output

I lv GPLT!  It's  fn gm!

##### AC Answers：（采用数组标记法）

```c
#include <stdio.h>
#include <string.h>
void del_chr( char *s, char ch )
{
    char *t=s;
    while( *s != '\0' )
    {
        if ( *s != ch )
            *t++=*s;
        s++ ;
    }
    *t='\0';
}
int main(){
    char a[10001];
    char b[10001];

    while (gets(a) != NULL && gets(b) != NULL){
        for(int i=0;i<strlen(b);i++){
            del_chr(a,b[i]);
        }
        printf("%s\n",a);
    }
    return 0;
}
```

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s1[1006], s2[1006], s3[256];

int main(){
    int len1, len2, i;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    while(fgets(s1, 1006, stdin)){
        len1 = strlen(s1);
        gets(s2);
        len2 = strlen(s2);
        memset(s3, 0, sizeof s3);
        for(i=0; i<len2; i++){
            s3[s2[i]]=1;
        }
        for(i=0; i<len1; i++){
            if(!s3[s1[i]]){
                putchar(s1[i]);
            }
        }
    }

    return 0;
}
```

比较做法也可以，不会TLE。

```
#include <stdio.h>
#include <string.h>
int main()
{
    char A[10001],B[10001];
    int i,j,a,b;
    j=0;
    while(gets(A)!=NULL)
    {
        gets(B);
        a=strlen(A);
        b=strlen(B);
        for(i=0;i<=a-1;i++)
            {
                for(j=0;j<=b-1;j++)
                {
                    if(A[i]==B[j])
                        break;
                }
                if(A[i]!=B[j])
                printf("%c",A[i]);
            }
        printf("\n");
    A[10001]=0;
    B[10001]=0;
    }
    return 0;
}
```

