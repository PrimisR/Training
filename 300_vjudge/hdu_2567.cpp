#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d\n",&n);
    while (n--) {
        char a[100],b[100];
        int i,j;
        gets(a);
        gets(b);
        int lena=(int)strlen(a),lenb=(int)strlen(b);
        for (i=0; i<(lena/2); i++) {
            printf("%c",a[i]);
        }
        for (j=0; j<lenb; j++) {
            printf("%c",b[j]);
        }
        for (i=(lena/2); i<lena; i++) {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}