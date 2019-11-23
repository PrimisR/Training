#include<stdio.h>

#define N 10

int n;
int total;
int num=1;
int i;
int j;
int mat[N][N];

int main(){
	while(~scanf("%d",&n)){
	i=0;
	j=0;
	num=1;
	total=n;
	while(n>0){
		for(int a=0;a<n;a++)
			{mat[i][j]=num++;
			i++;}
		n--;
		i--;
		j++;
		for(int b=0;b<n;b++)
			{mat[i][j]=num++;
			j++;}
		j--;
		i--;
		for(int c=0;c<n;c++)
			{mat[i][j]=num++;
			i--;}
		i++;
		j--;
		n--;
		for(int d=0;d<n;d++)
			{mat[i][j]=num++;
			j--;}
		j++;
		i++;
	}
	for(j=0;j<total;j++)
		{for(i=0;i<total;i++)
			printf("%d ",mat[i][j]);
		printf("\n");}
}
	return 0;
}

