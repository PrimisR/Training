#include<stdio.h>
#include<string.h>
int main()
{
	int length,i,count;
	char str[101] ;
	while(scanf("%s",str) != EOF && str[0] != '#'){
		count = 0;
		length = strlen(str);
		for(i = 0; i<length-1;i++){
			if(str[i]=='1'){
				count++;
			} 
		}
		if(count%2==0 && str[length-1] == 'e'){
			str[length-1]='0';
		}else if(count%2!=0 && str[length-1] == 'e'){
			str[length-1]='1';
		}else if(count%2==0 && str[length-1] == 'o'){
			str[length-1]='1';
		}else if(count%2!=0 && str[length-1] == 'o'){
			str[length-1]='0';
		}
		for(i = 0; i<length;i++){
			printf("%c",str[i]);
			if(i == length-1){
				printf("\n");
			}
		}
	}
	return 0;
}