#include <stdio.h>
#include <string.h>

#define N 10001

int label[N];
char a[N];
char b[N];
char c[N];
int lena;
int lenb;
int j;

int main(){
	while(scanf("%[^\n]",a)==1){
	getchar();
	scanf("%[^\n]",b);
	j=0;
	lena=strlen(a);
	lenb=strlen(b);
	for(int i=0;i<lenb;i++)
		label[b[i]]=1;
	for(int i=0;i<lena;i++)
		if(label[a[i]]==0)
			{c[j]=a[i];
			j++;}
	printf("%s\n",c);
	getchar();
	for(int i=0;i<N;i++)
	{label[i]=0;
	a[i]='\0';
	b[i]='\0';
	c[i]='\0';}
}
	return 0;
}
