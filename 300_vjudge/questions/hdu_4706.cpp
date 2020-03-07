#include <iostream>
#include <string.h>
using namespace std;
char f[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
          'o','p','q','r','s','t','u','v','w','x','y','z'};
int t;
char map[12][12];
 
void Display(int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			map[i][j]=' ';
	for(i=0;i<n;i++)                  {map[i][0]=f[(t%26)];t++;}
	for(i=n-2,j=1;i>0,j<n-1;i--,j++)  {map[i][j]=f[(t%26)];t++;}
    for(i=0;i<n;i++)                  {map[i][n-1]=f[(t%26)];t++;}   
    for(i=0;i<n;i++){
       for(j=0;j<n;j++)
           cout<<map[i][j];
       cout<<endl;
	}
}
int main()
{
	t=0;
   for(int i=3;i<=10;i++)
      Display(i);
   return 0;
}