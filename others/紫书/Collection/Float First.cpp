#include<stdio.h>
int main()
{
	float balance,bonus;
	char gender;
	printf("Please put in gender(F/M):\n");
	gender=getchar();
    read:
	printf("Wrong Input.\n");
	printf("Please put in gender(F/M):\n");
	scanf(" %c",&gender);//需要空格 
    if(gender!='F'&&gender!='M') 
	goto read;//用while写也可以 
	//如果输入错误，则重新输入 
	if(gender=='F'||gender=='M')
	printf("Please put in balance:\n");
	scanf("%f",&balance);
	{
	if(gender=='F')
			{
		if(balance>5000)
		bonus=0.05*balance;
		else
		bonus=0.02*balance;
			}	 	
	else
		bonus=0.02*balance;
	balance=balance+bonus;
	printf("%f",balance);
	}
	return 0;
 }
