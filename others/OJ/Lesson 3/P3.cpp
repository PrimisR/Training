#include <stdio.h>

#define N 10

int n;
int i;
int num=1;
int mat[N][N];

int main(){
	while(~scanf("%d",&n)){
	i=0;
	num=1;
	for(int j=0;j<n;j++)
	{
		for(int a=0;a<n;a++){
			mat[i][j]=num++;
			i++;}
		j++;
		i--;
		for(int a=0;a<n;a++){
			mat[i][j]=num++;
			i--;}
		i++;
	}
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++)
			printf("%d ",mat[k][j]);
		printf("\n");}
}
	return 0;
} 
