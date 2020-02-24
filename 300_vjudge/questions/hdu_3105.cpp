#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,a[111][6],aa[50];
	
	while(scanf("%d",&n),n!=0)
	{
		for(i=1;i<50;i++)
			aa[i]=i;aa[0]=0;
		for(i=0;i<n;i++)
			for(j=0;j<6;j++)
			{
				scanf("%d",&a[i][j]);
				aa[a[i][j]]=0;
			}
			for(i=1;i<50;i++)
				if(aa[i]!=0) break;
				if(i==50)printf("Yes\n");
				else printf("No\n");
    }
	return 0;
}
