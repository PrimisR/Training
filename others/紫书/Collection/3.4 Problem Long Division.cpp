#include <stdio.h>
#include <string.h>

int count;
char s[20];
char buffer[99];
int x;
int y;
int z;


int main()
{
	scanf("%s",s);
	for(int abc=100;abc<=999;abc++)//abc��de��Ϊ������ 
		for(int de=10;de<=99;de++)
		{
			x=abc*(de%10);//��ʽ��һ�� 
			y=abc*(de/10);//��ʽ�ڶ��� 
			z=abc*de;//��ʽ���
			sprintf(buffer,"%d%d%d%d%d",abc,de,x,y,z);
			//������������ӡ�뻺������ �����ǰ����������
			int ok=1;
			for(int i=0;i<strlen(buffer);i++)//����Ƚ� 
				if(strchr(s,buffer[i])==NULL)//�ַ����ַ����Ƚ�strchr
					ok=0;
			if(ok)
			{
				printf("<%d>\n",++count);//������ 
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
			}
		} 
		printf("The number of solutions=%d\n",count);
		return 0;
}
