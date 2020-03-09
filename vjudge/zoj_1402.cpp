#include <stdio.h>

int main()
{
    int g,N[31];
    while(scanf("%d",&g)!=EOF&&g)
    {
        int i,j;
        for(i=1;i<=g;i++)
            scanf("%d",&N[i]);

        int sam=0,ella=0;
        for(i=1,j=g;i<=j;)
        {
            if(sam<=ella)
            {
                sam+=N[i++];
            }
            else
            {
                ella+=N[j--];
            }
        }

        if(sam==ella)
        {
            printf("Sam stops at position %d and Ella stops at position %d.\n",i-1,j+1);
        }
        else
        {
            printf("No equal partitioning.\n");
        }
    }

    return 0;
}