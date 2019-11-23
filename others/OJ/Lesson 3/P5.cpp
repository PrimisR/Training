#include <stdio.h>

int n;
int money;
int bottle;
int cap;
int beer;
int add_beer;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	scanf("%d",&money);
	beer=money/2;
	cap=beer;
	bottle=beer;
	while(cap>=4||bottle>=2)
	{
		add_beer=cap/4+bottle/2;
		beer+=add_beer;
		cap=cap%4+add_beer;
		bottle=bottle%2+add_beer;
	}
	printf("%d\n",beer);
}
	return 0;
} 
