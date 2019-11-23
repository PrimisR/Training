#include <stdio.h>

#define LEN 19
#define FIG 17
#define N 1000

int n;
int error;
int correct;
int z;
char m;
char id[N][LEN];
int weight[FIG]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

char ztom(int a){
	if(a>=3) return(12-a+'0');
	if(a==0) return('1');
	if(a==1) return('0');
	if(a==2) return('X');
}

int main(){
	while(~scanf("%d",&n)){
	correct=0;
	for(int i=0;i<n;i++)
		scanf("%s",id[i]);
	for(int i=0;i<n;i++){
		z=0;
		error=0;
		for(int j=0;j<FIG;j++){
			z+=(weight[j]*(id[i][j]-'0'));
			if(id[i][j]<'0'||id[i][j]>'9')
				error=1;}
			m=ztom(z%11);
			if(m!=id[i][FIG])
				error=1;
			if(error)
				printf("%s\n",id[i]);
			else
				correct++;}
	if(correct==n)
		printf("All passed\n");
}
	return 0;
}
