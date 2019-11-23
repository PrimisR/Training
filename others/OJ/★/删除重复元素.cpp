#include <stdio.h>
#include <memory.h>

#define N 10000
#define L 100000

int n;
int m;
int m_len;
int s_len;
int found;
int k[N];
int id[N][N];
int target[N];
int search[N];
int match[N];
int d_label[L];
int s_label[L];

int main()
{
//---------------------------------------------------//读取 
	while(~scanf("%d",&n)){
	m_len=0;
	s_len=0;
	memset(d_label,0,sizeof(d_label));
	memset(s_label,0,sizeof(s_label));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++)
			scanf("%d",&id[i][j]);	
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",&target[i]);
//---------------------------------------------------//删除重复元素 
	for(int i=0;i<m;i++)
		if(d_label[target[i]]==0)
		{
			search[s_len++]=target[i];
			d_label[target[i]]=1;
		}
//---------------------------------------------------//标记 
	for(int r=0;r<n;r++)
		for(int c=0;c<k[r];c++)
		{
			if(k[r]==1)
				s_label[id[r][c]]=2;
			else
				s_label[id[r][c]]=1;	
		}
//---------------------------------------------------//match
	for(int i=0;i<s_len;i++)
		if(s_label[search[i]]!=1)
			match[m_len++]=search[i];
//---------------------------------------------------//输出 
	if(m_len)
	{
		for(int i=0;i<m_len;i++)
		{
			printf("%05d",match[i]);
			if(i!=m_len-1)
				printf(" ");
		}
		printf("\n");
	}
	else
		printf("No one is handsome\n");
}
	return 0;
}
