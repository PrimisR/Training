#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxn=30;
int n;
vector<int> pile[maxn]; //ÿ��pile[i]��һ��vector��ע��������ʽint a[maxn]
 
//Ѱ��ľ��a���ڵ�pile��height�������õ���ʽ���ص����ߣ���������ֵ��
void find_block(int a,int &p,int &h)
{
	for(p=0;p<n;p++)
		for(h=0;h<pile[p].size();h++)
			if(pile[p][h]==a) return; 
}

//�ѵ�p�Ѹ߶�Ϊh��ľ���Ϸ�������ľ���ƻ�ԭλ(����β��)
void clear_above(int p,int h)
{
	for(int i=h+1;i<pile[p].size();i++)
	{
		int b=pile[p][i];
		pile[b].push_back(b);	
	}//��ľ��bpushback��ÿ��pile����
	pile[p].resize(h+1);//��pileֻʣ���±�0-h��Ԫ�� 
}

void pile_onto(int p,int h,int p2)//�ѵ�p�Ѹ߶�Ϊh�����Ϸ���ľ�������ƶ���p2�Ѷ��� 
{
	for(int i=h;i<pile[p].size();i++)
		pile[p2].push_back(pile[p][i]); 
	pile[p].resize(h);//�����룬����� 
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
	for(int i=0;i<n;i++) pile[i].push_back(i);//����ÿһ��push_back����block
	while(cin>>s1&&s1!="quit")//�������� 
	{
		cin>>a>>s2>>b;
		int pa,ha,pb,hb;
		find_block(a,pa,ha);
		find_block(b,pb,hb);//Ѱ�ң�����p��h 
		if(pa==pb) continue;//�����Ϊ�Ƿ�ָ����¶�ȡ�����ص�while��continue��
		//�������������onto�����b���棬���move�����a����
		//���pile������a�������е�ľ�飬���over������b����ľ��ѵĶ��� 
		if(s2=="onto") clear_above(pb,hb);
		if(s1=="move") clear_above(pa,ha);
		pile_onto(pa,ha,pb);//�����a���㣬��a����û��ľ��
	}
	print();
	return 0;
}
