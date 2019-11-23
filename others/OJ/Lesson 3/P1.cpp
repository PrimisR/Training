#include <stdio.h>

#define N 1001

int n;
int k;
int r;
int matrix[N][N];
int r_matrix[N][N];

int main(){
	while(~scanf("%d",&n)){
	scanf("%d",&k);
	r=k%4;
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			scanf("%d",&matrix[i][j]);
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++){
			if(r==0) r_matrix[i][j]=matrix[i][j];
			if(r==1) r_matrix[n-j+1][i]=matrix[i][j];
			if(r==2) r_matrix[n-i+1][n-j+1]=matrix[i][j];
			if(r==3) r_matrix[j][n-i+1]=matrix[i][j];}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++)
				printf("%d ",r_matrix[i][j]);
			printf("\n");}
}
	return 0;
}


