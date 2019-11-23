#include <stdio.h>
#include <string.h>
#include <memory.h>

char string[10001];
char output[10001];
int len;
int g;
int p;
int l;
int t;
int total;
int pose;

int main()
{
	while(~scanf("%s",string)){
	getchar();
	memset(output,'\0',sizeof(output));
	g=0;
	p=0;
	l=0;
	t=0;
	pose=0;
	len=strlen(string);
	for(int i=0;i<len;i++)
	{
		if(string[i]=='g'||string[i]=='G') g++;
		if(string[i]=='p'||string[i]=='P') p++;
		if(string[i]=='l'||string[i]=='L') l++;
		if(string[i]=='t'||string[i]=='T') t++;
	}
	total=g+p+l+t;
	while(total>0)
	{
		if(g) {output[pose]='G'; pose++; g--; total--;}
		if(p) {output[pose]='P'; pose++; p--; total--;}
		if(l) {output[pose]='L'; pose++; l--; total--;}
		if(t) {output[pose]='T'; pose++; t--; total--;}
	}
	printf("%s\n",output);
}
}
