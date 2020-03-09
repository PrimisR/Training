#include <stdio.h>
int main()
{
    int  nCase;
    int  y;
    char  ch;
    scanf("%d",&nCase);
    getchar();
    while(nCase--)
    {
        scanf("%c %d",&ch,&y);
        getchar();
 
        if(ch>='A'&&ch<='Z')
            printf("%d\n",y+ch-'A'+1);
        else
            printf("%d\n",y-(ch-'a'+1));
    }
    
    return 0;
}