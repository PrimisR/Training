#include<stdio.h>
 
const int Dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
 
int N,Ans,HashMap[10][10];
 
char Map[10][10];
 
void UpdateHashMap(int Row,int Col,int Val)
{
	for(int n=0;n<4;++n)
	{
		int tmprow=Row;
		int tmpcol=Col;
		while(1)
		{
			if(!(0<=tmprow&&tmprow<N))   { break; }
			if(!(0<=tmpcol&&tmpcol<N))   { break; }
			if(Map[tmprow][tmpcol]!='.') { break; }
			HashMap[tmprow][tmpcol]+=Val;
			tmprow+=Dir[n][0];
			tmpcol+=Dir[n][1];
		}
	}
}
 
void DFS(int Row,int Col,int ChessNum)
{
	if(Col==N) 
	{ 
		++Row;  Col=0; 
	}
	if(Row==N)
	{ 
		Ans=(Ans>ChessNum?Ans:ChessNum);  return; 
	}
	if(Map[Row][Col]=='.'&&!HashMap[Row][Col])
	{
		UpdateHashMap(Row,Col,1);
		DFS(Row,Col+1,ChessNum+1);
		UpdateHashMap(Row,Col,-1);
	}
	DFS(Row,Col+1,ChessNum);
}
 
int main()
{
	while(scanf("%d",&N)==1&&N)
	{
		Ans=0;
		for(int i=0;i<N;++i)
		{ 
			scanf("%s",Map[i]);
		}
		DFS(0,0,0);
		printf("%d\n",Ans);
	}
	return 0;
}