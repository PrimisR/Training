#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxn=30;
int n;
vector<int> pile[maxn]; //每个pile[i]是一个vector，注意声明方式int a[maxn]
 
//寻找木块a所在的pile和height，以引用的形式返回调用者（返回两个值）
void find_block(int a,int &p,int &h)
{
	for(p=0;p<n;p++)
		for(h=0;h<pile[p].size();h++)
			if(pile[p][h]==a) return; 
}

//把第p堆高度为h的木块上方的所有木块移回原位(放在尾部)
void clear_above(int p,int h)
{
	for(int i=h+1;i<pile[p].size();i++)
	{
		int b=pile[p][i];
		pile[b].push_back(b);	
	}//把木块bpushback回每个pile后面
	pile[p].resize(h+1);//让pile只剩下下标0-h的元素 
}

void pile_onto(int p,int h,int p2)//把第p堆高度为h及其上方的木块整体移动到p2堆顶部 
{
	for(int i=h;i<pile[p].size();i++)
		pile[p2].push_back(pile[p][i]); 
	pile[p].resize(h);//先输入，再清除 
}

void print()
{
	for(int i=0;i<n;i++)
	{
		printf("%d:",i);
		for(int j=0;j<pile[i].size();j++)
		printf(" %d",pile[i][j]);
		printf("\n");
	}
}


int main()
{
	int a,b;
	cin>>n;
	string s1,s2;
	for(int i=0;i<n;i++) pile[i].push_back(i);//先向每一堆push_back本身block
	while(cin>>s1&&s1!="quit")//不断输入 
	{
		cin>>a>>s2>>b;
		int pa,ha,pb,hb;
		find_block(a,pa,ha);
		find_block(b,pb,hb);//寻找，返回p和h 
		if(pa==pb) continue;//相等则为非法指令，重新读取（返回到while，continue）
		//分析条件：如果onto，清空b上面，如果move，清空a上面
		//如果pile，操作a上面所有的木块，如果over，放在b所在木块堆的顶部 
		if(s2=="onto") clear_above(pb,hb);
		if(s1=="move") clear_above(pa,ha);
		pile_onto(pa,ha,pb);//如果把a清零，则a上面没有木块
	}
	print();
	return 0;
}
